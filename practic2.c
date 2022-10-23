#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h> // system("cls");

float sideA, sideB, sideC;
void calculationsOutput(), inputData(), clear();
int verifyResult(), verifyNumb(float *);

// main function
int main()
{
    inputData();
    calculationsOutput();
    getch();
}

// input and veritying a data
void inputData()
{
    do
    {
        do
        {
            system("cls");
            printf("Enter the size of the A-side in cm: ");
        } while (verifyNumb(&sideA) == 0);
        do
        {
            system("cls");
            printf("Enter the size of the A-side in cm: %0.2f \n", sideA);
            printf("Enter the size of the B-side in cm: ");
        } while (verifyNumb(&sideB) == 0);
        do
        {
            system("cls");
            printf("Enter the size of the A-side in cm: %0.2f \n", sideA);
            printf("Enter the size of the B-side in cm: %0.2f \n", sideB);
            printf("Enter the size of the C-side in cm: ");
        } while (verifyNumb(&sideC) == 0);
    } while (verifyResult() == 0);
}

// function for veritying every number
int verifyNumb(float *hrefToSide)
{
    char input_char[20], output_int[20];
    int position, arr_size, new_position;
    float num;
    scanf("%s", &input_char);
    arr_size = (sizeof(input_char) / sizeof(input_char[0]));
    for (position = 0; position < arr_size; position++)
    {
        if ((input_char[position] >= 'a' && input_char[position] <= 'z') || (input_char[position] >= 'A' && input_char[position] <= 'Z'))
        {
            for (new_position = position; new_position < arr_size; new_position++)
            {
                input_char[new_position] = input_char[new_position + 1];
            }
            arr_size--;
            position = -1;
        }
    }
    *hrefToSide = atof(input_char);

    if (*hrefToSide <= 0)
    {
        clear();
        return 0;
    }
    else
    {
        return 1;
    }
}

// function for veritying the result
int verifyResult()
{
    if (((sideA + sideB) > sideC) && ((sideB + sideC) > sideA) && ((sideA + sideC) > sideB))
    {
        return 1;
    }
    else
    {
        printf("Please, enter a new data. This triangle does not exist.\n");
        printf("Press any button to continue.\n");
        getch();
        return 0;
    }
}

// function that clear the buffer
void clear()
{
    int character;
    while ((character = getchar()) != '\n' && character != EOF) // end of file
        ;
}

// function that calculate and output the data
void calculationsOutput()
{
    float squareTr, perimeter, heightA, heightB, heightC, medianA, medianB, medianC, bisectorA, bisectorB, bisectorC;
    float square(float numbToSqr)
    {
        return numbToSqr * numbToSqr;
    }
    float halfPer = ((sideA + sideB + sideC) / 2);
    squareTr = sqrt((halfPer - sideA) * (halfPer - sideB) * (halfPer - sideC) * halfPer);
    perimeter = (sideA + sideB + sideC);
    heightA = ((2 * sqrt((halfPer - sideA) * (halfPer - sideB) * (halfPer - sideC) * halfPer)) / sideA);
    heightB = ((2 * sqrt((halfPer - sideA) * (halfPer - sideB) * (halfPer - sideC) * halfPer)) / sideB);
    heightC = ((2 * sqrt((halfPer - sideA) * (halfPer - sideB) * (halfPer - sideC) * halfPer)) / sideC);
    medianA = (sqrt(2 * square(sideB) + 2 * square(sideC) - square(sideA)));
    medianB = (sqrt(2 * square(sideA) + 2 * square(sideC) - square(sideB)));
    medianC = (sqrt(2 * square(sideB) + 2 * square(sideA) - square(sideC)));
    bisectorA = (2 / (sideB + sideC) * sqrt(sideB * sideC * halfPer * (halfPer - sideA)));
    bisectorB = (2 / (sideA + sideC) * sqrt(sideA * sideC * halfPer * (halfPer - sideB)));
    bisectorC = (2 / (sideB + sideA) * sqrt(sideB * sideA * halfPer * (halfPer - sideC)));
    printf("Area of a triangle: %f cm^2\n", squareTr);
    printf("Perimeter of a triangle: %f cm\n", perimeter);
    printf("Heights on sides a, b, c: %f cm, %f cm, %f cm\n", heightA, heightB, heightC);
    printf("Medians on sides a, b, c: %f cm, %f cm, %f cm \n", medianA, medianB, medianC);
    printf("Bisectors on sides a, b, c: %f cm, %f cm, %f cm \n", bisectorA, bisectorB, bisectorC);
}
