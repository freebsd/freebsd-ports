--- image.cxx.orig	2006-11-18 14:56:11.000000000 +0100
+++ image.cxx	2012-05-09 12:28:28.000000000 +0200
@@ -92,6 +92,7 @@
 
 #ifdef HAVE_LIBPNG
 #  include <png.h>
+#  include <zlib.h>
 #endif // HAVE_LIBPNG
 
 
