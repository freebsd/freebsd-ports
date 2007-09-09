--- ./UI/TechTreeWnd.cpp.orig	Fri Aug 10 21:45:52 2007
+++ ./UI/TechTreeWnd.cpp	Sat Sep  8 15:48:32 2007
@@ -55,6 +55,10 @@
     const double MIN_SCALE = 0.1073741824;  // = 1.0/(1.25)^10
     const double MAX_SCALE = 1.0;
 
+    const double PI = 3.141594;
+
+    double PS2INCH(double x) { return PS2INCH(x); }
+
     pointf Bezier(pointf* patch, double t)
     {
         pointf temp[6][6];
