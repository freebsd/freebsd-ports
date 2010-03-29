--- pngconf.h.orig	2010-02-25 12:38:29.000000000 +0100
+++ pngconf.h	2010-03-28 19:35:29.000000000 +0200
@@ -499,7 +499,7 @@
 #  ifndef PNG_NO_READ_INVERT
 #    define PNG_READ_INVERT_SUPPORTED
 #  endif
-#if 0 /* removed from libpng-1.4.0 */
+#if 1 /* removed from libpng-1.4.0 */
 #  ifndef PNG_NO_READ_DITHER
 #    define PNG_READ_DITHER_SUPPORTED
 #  endif
