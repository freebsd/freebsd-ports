--- src/MatrixImplementation.hpp.orig	Thu Jan 11 21:31:51 2007
+++ src/MatrixImplementation.hpp	Thu Jan 11 21:33:18 2007
@@ -37,18 +37,18 @@
    //@{
 
    template <class T>
-   Matrix<T>::Matrix<T>()
+   Matrix<T>::Matrix()
          : v((size_t)0), r(0), c(0), s(0)
    {}
 
 
    template <class T>
-   Matrix<T>::Matrix<T>(size_t rows, size_t cols)
+   Matrix<T>::Matrix(size_t rows, size_t cols)
          : v(rows * cols), r(rows), c(cols), s(rows * cols)
    {}
 
    template <class T>
-   Matrix<T>::Matrix<T>(size_t rows, size_t cols,
+   Matrix<T>::Matrix(size_t rows, size_t cols,
                   T initialValue)
          : v(rows * cols, initialValue), r(rows), c(cols), s(rows * cols)
    {}
