--- matrix/matrix_complex.cpp.orig	2008-02-13 22:27:09.000000000 +0100
+++ matrix/matrix_complex.cpp	2008-02-13 22:27:30.000000000 +0100
@@ -27,7 +27,7 @@
 
 namespace PLib {
 
-  double Matrix<Complex>::norm(void){
+  template<> double Matrix<Complex>::norm(void){
     int i,j ;
     double sumR, sumI, maxsum;
     int init=0 ;
