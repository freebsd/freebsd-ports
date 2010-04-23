--- libgd/gd_png.c.orig	2009-03-14 18:48:42.000000000 +0100
+++ libgd/gd_png.c	2010-04-05 19:54:05.000000000 +0200
@@ -139,7 +139,11 @@
 		return NULL;
 	}
 
+#if PNG_LIBPNG_VER >= 10400
+	if (png_sig_cmp (sig, 0, 8)) { /* bad signature */
+#else
 	if (!png_check_sig (sig, 8)) { /* bad signature */
+#endif
 		return NULL;
 	}
 
