--- matrix/matrix_int.cpp.orig	2008-02-13 22:11:44.000000000 +0100
+++ matrix/matrix_int.cpp	2008-02-13 22:12:25.000000000 +0100
@@ -29,11 +29,11 @@
 
 namespace PLib {
 
-  void Matrix<int>::qSort(){
+  template<> void Matrix<int>::qSort(){
     qsort((char*)m,rows()*cols(),sizeof(int),compareInt) ;
   }
   
-  Matrix<int>&
+  template<> Matrix<int>&
     Matrix<int>::operator*=(double a)
     {
       int *p1 ;
@@ -46,7 +46,7 @@
       return *this ;
     }
   
-  Matrix<int>&
+  template<> Matrix<int>&
     Matrix<int>::operator+=(double a)
     {
       int *p1 ;
@@ -57,7 +57,7 @@
       return *this ;
     }
 
-  Matrix<int>&
+  template<> Matrix<int>&
     Matrix<int>::operator-=(double a)
     {
       int *p1 ;
@@ -68,7 +68,7 @@
       return *this ;
     }
   
-  Matrix<int>&
+  template<> Matrix<int>&
     Matrix<int>::operator/=(double a)
     {
       int *p1 ;
