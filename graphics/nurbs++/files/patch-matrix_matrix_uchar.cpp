--- matrix/matrix_uchar.cpp.orig	2008-02-13 22:39:32.000000000 +0100
+++ matrix/matrix_uchar.cpp	2008-02-13 22:40:11.000000000 +0100
@@ -27,7 +27,7 @@
 
 namespace PLib {
 
-  Matrix<unsigned char>&
+  template<> Matrix<unsigned char>&
     Matrix<unsigned char>::operator*=(double a)
     {
       unsigned char *p1 ;
@@ -40,7 +40,7 @@
       return *this ;
     }
   
-  Matrix<unsigned char>&
+  template<> Matrix<unsigned char>&
     Matrix<unsigned char>::operator+=(double a)
     {
       unsigned char *p1 ;
@@ -52,7 +52,7 @@
     }
   
   
-  Matrix<unsigned char>&
+  template<> Matrix<unsigned char>&
     Matrix<unsigned char>::operator-=(double a)
     {
       unsigned char *p1 ;
@@ -64,7 +64,7 @@
     }
   
   
-  Matrix<unsigned char>&
+  template<> Matrix<unsigned char>&
     Matrix<unsigned char>::operator/=(double a)
     {
       unsigned char *p1 ;
