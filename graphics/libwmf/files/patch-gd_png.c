--- src/extra/gd/gd_png.c.orig	2010-03-28 12:44:53.000000000 +0200
+++ src/extra/gd/gd_png.c	2010-03-28 12:45:16.000000000 +0200
@@ -136,7 +136,7 @@
   /* first do a quick check that the file really is a PNG image; could
    * have used slightly more general png_sig_cmp() function instead */
   gdGetBuf (sig, 8, infile);
-  if (!png_check_sig (sig, 8))
+  if (png_sig_cmp (sig, 0, 8))
     return NULL;		/* bad signature */
 
 #ifndef PNG_SETJMP_NOT_SUPPORTED
