--- src/IMG_savepng.cpp.orig	2011-04-08 16:11:45.000000000 +0200
+++ src/IMG_savepng.cpp	2012-05-25 18:51:10.000000000 +0200
@@ -27,6 +27,7 @@
 
 #ifdef IMPLEMENT_SAVE_PNG
 #include <png.h>
+#include <zlib.h>
 #endif
 
 #include <stdlib.h>
