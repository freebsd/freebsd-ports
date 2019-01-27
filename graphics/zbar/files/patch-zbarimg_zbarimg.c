--- zbarimg/zbarimg.c.orig	2009-10-23 18:16:44 UTC
+++ zbarimg/zbarimg.c
@@ -38,7 +38,11 @@
 #include <assert.h>
 
 #include <zbar.h>
+#if MAGICK_MAJOR < 7
 #include <wand/MagickWand.h>
+#else
+#include <MagickWand/MagickWand.h>
+#endif
 
 /* in 6.4.5.4 MagickGetImagePixels changed to MagickExportImagePixels.
  * (still not sure this check is quite right...
