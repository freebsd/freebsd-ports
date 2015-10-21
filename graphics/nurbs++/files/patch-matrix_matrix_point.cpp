--- matrix/matrix_point.cpp.orig	2008-02-13 22:22:23.000000000 +0100
+++ matrix/matrix_point.cpp	2008-02-13 22:23:16.000000000 +0100
@@ -27,7 +27,7 @@
 
 namespace PLib {
 
-  double
+  template<> double
     Matrix<Point3Df>::norm(void) {
     int i,j ;
     double sumX, sumY, sumZ, maxsum;
@@ -55,7 +55,7 @@
     return sqrt(maxsum);
   }
   
-  double
+  template<> double
     Matrix<Point3Dd>::norm(void) {
     int i,j ;
     double sumX, sumY, sumZ, maxsum;
@@ -83,7 +83,7 @@
     return sqrt(maxsum);
   }
   
-  double
+  template<> double
     Matrix<Point2Df>::norm(void) {
     int i,j ;
     double sumX, sumY, sumZ, maxsum;
@@ -111,7 +111,7 @@
     return sqrt(maxsum);
   }
 
-  double
+  template<> double
     Matrix<Point2Dd>::norm(void) {
     int i,j ;
     double sumX, sumY, sumZ, maxsum;
