--- matrix/matrix_char.cpp.orig	2008-02-13 22:21:07.000000000 +0100
+++ matrix/matrix_char.cpp	2008-02-13 22:21:42.000000000 +0100
@@ -27,7 +27,7 @@
 
 namespace PLib {
 
-  Matrix<char>&
+  template<> Matrix<char>&
     Matrix<char>::operator*=(double a)
     {
       char *p1 ;
@@ -40,7 +40,7 @@
       return *this ;
     }
   
-  Matrix<char>&
+  template<> Matrix<char>&
     Matrix<char>::operator+=(double a)
     {
       char *p1 ;
@@ -51,7 +51,7 @@
       return *this ;
     }
   
-  Matrix<char>&
+  template<> Matrix<char>&
     Matrix<char>::operator-=(double a)
     {
       char *p1 ;
@@ -62,7 +62,7 @@
       return *this ;
     }
   
-  Matrix<char>&
+  template<> Matrix<char>&
     Matrix<char>::operator/=(double a)
     {
       char *p1 ;
