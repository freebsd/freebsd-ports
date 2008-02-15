--- matrix/matrix_hpoint.cpp.orig	2008-02-13 22:23:41.000000000 +0100
+++ matrix/matrix_hpoint.cpp	2008-02-13 22:24:43.000000000 +0100
@@ -27,7 +27,7 @@
 
 namespace PLib {
 
-  double
+  template<> double
     Matrix<HPoint3Df>::norm(void) {
     int i,j ;
     double sumX, sumY, sumZ, sumW, maxsum;
@@ -58,7 +58,7 @@
   }
   
   
-  double
+  template<> double
     Matrix<HPoint3Dd>::norm(void) {
     int i,j ;
     double sumX, sumY, sumZ, sumW, maxsum;
@@ -89,7 +89,7 @@
   }
   
   
-  double
+  template<> double
     Matrix<HPoint2Df>::norm(void) {
     int i,j ;
     double sumX, sumY, sumZ, sumW, maxsum;
@@ -119,7 +119,7 @@
     return sqrt(maxsum);
   }
   
-  double
+  template<> double
     Matrix<HPoint2Dd>::norm(void) {
     int i,j ;
     double sumX, sumY, sumZ, sumW, maxsum;
