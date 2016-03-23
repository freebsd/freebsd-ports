--- src/fileformat/ppmio.cpp.orig	2009-05-25 19:24:49 UTC
+++ src/fileformat/ppmio.cpp
@@ -34,6 +34,8 @@ extern "C" {
 #include <math.h>
 #include <assert.h>
 
+#define log2(x)	((float)log(x)/log(2))
+
 struct PPMData
 {
     pixval maxPV;
