--- library/tulip/src/Color.cpp.orig	2007-12-18 21:27:11.000000000 +0100
+++ library/tulip/src/Color.cpp	2007-12-18 21:40:14.000000000 +0100
@@ -49,10 +49,14 @@
 
 //// static RGB<->HSV conversion functions
 void RGBtoHSV(unsigned char r, unsigned char g, unsigned char b, int &h, int &s, int &v) {
-  int min, max, delta;
-  // "<?" and ">?" are GNU G++ extensions; may not work with other compiler
-  min = r <? g <? b;
-  max = r >? g >? b;
+  int min, max, delta, tmp;
+  
+  tmp = (r < g) ? r : g;
+  min = (b < tmp) ? b : tmp;
+
+  tmp = (r > g) ? r : g;
+  max = (b > tmp) ? b : tmp;
+
   v = max;				// v
 
   delta = max - min;
