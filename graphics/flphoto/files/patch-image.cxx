--- image.cxx.orig	2006-11-18 13:56:11 UTC
+++ image.cxx
@@ -92,6 +92,7 @@ extern "C" {
 
 #ifdef HAVE_LIBPNG
 #  include <png.h>
+#  include <zlib.h>
 #endif // HAVE_LIBPNG
 
 
