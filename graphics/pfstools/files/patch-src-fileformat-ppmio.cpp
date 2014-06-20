--- src/fileformat/ppmio.cpp.orig	2009-05-25 19:24:49.000000000 +0000
+++ src/fileformat/ppmio.cpp	2014-02-20 19:04:01.556587853 +0000
@@ -34,6 +34,8 @@
 #include <math.h>
 #include <assert.h>
 
+#define log2(x)	((float)log(x)/log(2))
+
 struct PPMData
 {
     pixval maxPV;
