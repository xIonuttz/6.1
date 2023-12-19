#include <iostream>
#include <cmath>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r, double i) : real(r), imaginary(i) {}

    // Overload + operator for sum
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Overload ~ operator for absolute value (module)
    double operator~() const {
        return std::sqrt(real * real + imaginary * imaginary);
    }

    // Function for power (assuming exponent is 2 by default)
    Complex power(int exponent = 2) const {
        if (exponent == 2) {
            // Square the complex number
            return Complex(real * real - imaginary * imaginary, 2 * real * imaginary);
        }
        else {
            // You can implement additional logic for higher exponents if needed
            std::cerr << "Exponentiation higher than 2 is not supported in this example.\n";
            return Complex(0, 0);
        }
    }

    // Display the complex number
    void display() const {
        std::cout << "(" << real << " + " << imaginary << "i)" << std::endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, -2);

    // Sum of two complex numbers
    Complex sum = c1 + c2;
    std::cout << "Sum: ";
    sum.display();

    // Absolute value (module) of a complex number
    double absValue = ~c1;
    std::cout << "Absolute Value (Module) of c1: " << absValue << std::endl;

    // Square of a complex number
    Complex square = c1.power();
    std::cout << "Square of c1: ";
    square.display();

    return 0;
}
