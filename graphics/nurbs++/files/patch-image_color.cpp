--- image/color.cpp.orig	2008-02-13 22:28:08.000000000 +0100
+++ image/color.cpp	2008-02-13 22:28:56.000000000 +0100
@@ -50,7 +50,7 @@
   Color blackColor(0,0,0) ;
   */
 
-  double
+  template<> double
     Matrix<Color>::norm(void) {
 #ifdef USE_EXCEPTION
     throw MatrixErr();
@@ -63,7 +63,7 @@
   }
 
 #ifndef USING_VCC
-  int Matrix<Color>::read(char* filename,int r, int c) {
+  template<> int Matrix<Color>::read(char* filename,int r, int c) {
     ifstream fin(filename) ;
     if(!fin) {
       resize(1,1) ;
@@ -89,7 +89,7 @@
   }
 #endif
 
-  int Vector<Color>::minIndex() const {
+  template<> int Vector<Color>::minIndex() const {
 #ifdef USE_EXCEPTION
     throw MatrixErr() ;
 #else
