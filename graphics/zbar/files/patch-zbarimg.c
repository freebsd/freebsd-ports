--- zbarimg/zbarimg.c	2009-10-23 14:16:44.000000000 -0400
+++ zbarimg/zbarimg.c	2017-08-10 10:22:08.707599000 -0400
@@ -39,5 +39,9 @@
 
 #include <zbar.h>
+#if MAGICK_MAJOR < 7
 #include <wand/MagickWand.h>
+#else
+#include <MagickWand/MagickWand.h>
+#endif
 
 /* in 6.4.5.4 MagickGetImagePixels changed to MagickExportImagePixels.
