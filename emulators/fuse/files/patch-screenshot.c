--- screenshot.c.orig	2011-01-12 22:36:28.000000000 +0100
+++ screenshot.c	2012-05-09 12:59:50.000000000 +0200
@@ -49,6 +49,7 @@
 #ifdef USE_LIBPNG
 
 #include <png.h>
+#include <zlib.h>
 
 static int get_rgb32_data( libspectrum_byte *rgb32_data, size_t stride,
 			   size_t height, size_t width );
