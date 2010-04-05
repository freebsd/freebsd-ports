--- libgd/gd_png.c.orig	2007-05-17 00:54:11.000000000 +0200
+++ libgd/gd_png.c	2010-04-05 20:43:02.000000000 +0200
@@ -136,7 +136,11 @@
 	   * have used slightly more general png_sig_cmp() function instead 
 	   */
 	gdGetBuf(sig, 8, infile);
+#if PNG_LIBPNG_VER >= 10400
+	if (png_sig_cmp (sig, 0, 8)) { /* bad signature */
+#else
 	if (!png_check_sig (sig, 8)) { /* bad signature */
+#endif
 		return NULL;
 	}
 
