--- src/nvimage/ImageIO.cpp.orig	2010-05-14 19:59:28.000000000 +0200
+++ src/nvimage/ImageIO.cpp	2012-05-06 20:50:40.000000000 +0200
@@ -599,6 +599,8 @@
 
 #if defined(HAVE_PNG)
 
+#include "pngpriv.h"
+
 static void user_read_data(png_structp png_ptr, png_bytep data, png_size_t length)
 {
 	nvDebugCheck(png_ptr != NULL);
