/*
 * This program lets the user input as many numbers as he wants. It then displays a menu that lets him compute the sum
 * of the numbers, compute the average or show either the smallest or biggest number among them.
 *
 * Author: Gerardo González Becerril.
 * E-mail: a01411981@itesm.mx
 * Date: October 14th, 2018.
 */

 // Library used.
 #include <stdio.h>

 // Function that uses a for loop to go through all the numbers in an array of a certain size. Each time it loops,
 // it adds to a number starting on 0 the number in the position of that loop. The function then returns that value.
float sum(int array[], int n) {
    float b = 0;
    for (int i = 0; i < n; i++) {
        b += array[i];
    }
    return b;
}

int main() {

    int x; // Variable for storing the user input.
    int n; // Variable for the amount of numbers the user will want to enter.
    int a; // Variable for taking the number of the selected menu.
    int selectedNumber; // Variable for storing the number that'll be determined to be either the biggest or smallest.

    // Asks the user for an amount.
    printf("How many numbers would you like to enter?\n");
    scanf("%i", &n);

    int array[n]; // Array that fits the numbers the user wants to enter.

    printf("You will now enter %i numbers.\n", n);

    // For loop that asks for a number the amount of times indicated by the user, then adds it to the corresponding
    // position in the array.
    for (int i = 0; i < n; i++) {
        printf("Give me number %i:\n", i + 1);
        scanf("%i", &x);
        array[i] = x;
    }

    // Asks the user for a menu selection.
    printf("What would you like to do with these numbers?\nPress '1' to compute the sum of the given numbers.\nPress '2' to compute the average of the given numbers.\nPress '3' to display the smallest value of the given numbers and the number of the cell where it is stored.\nPress '4' to display the biggest value of the given numbers and the number of the cell where it is stored.\n");
    scanf("%i", &a);

    // Switch statement to carry out the task selected by the user.
    switch(a) {
        case 1: // Uses the function sum to print the sum of the numbers in the array.
            printf("The sum of the numbers is %.1f.", sum(array, n));
            break;
        case 2: // Sums the numbers in the array, then divides the result by the amount of numbers and prints it.
            printf("The average of the numbers is %.1f.", sum(array, n)/ (sizeof(array)/sizeof(array[0])));
            break;
        case 3:
            selectedNumber = array[0]; // Currently selected number.
            // For loop that goes through all the numbers. If there's a smaller number than the currently selected,
            // it'll take its place.
            for (int i = 0; i < n; i++) {
                if (array[i] < selectedNumber) {
                    selectedNumber = array[i];
                }
            }
            printf("The smallest number is %i.", selectedNumber);
            break;
        case 4:
            selectedNumber = array[0]; // Currently selected number.
            // For loop that goes through all the numbers. If there's a bigger number than the currently selected,
            // it'll take its place.
            for (int i = 0; i < n; i++) {
                if (array[i] > selectedNumber) {
                    selectedNumber = array[i];
                }
            }
            printf("The biggest number is %i.", selectedNumber);
            break;
        default:
            printf("That is not available.");
    }

    return 0;

}