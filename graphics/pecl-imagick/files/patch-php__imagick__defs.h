--- php_imagick_defs.h.orig	2020-10-25 08:13:09 UTC
+++ php_imagick_defs.h
@@ -20,6 +20,10 @@
 #ifndef PHP_IMAGICK_DEFS_H /* PHP_IMAGICK_DEFS_H */
 # define PHP_IMAGICK_DEFS_H
 
+#ifndef HAVE_LOCALE_H
+#define HAVE_LOCALE_H
+#endif
+
 /* Include magic wand header */
 #if defined (IM_MAGICKWAND_HEADER_STYLE_SEVEN)
 #  include <MagickWand/MagickWand.h>
