--- cliplibs/clip-gd/gd/gd_png.c.orig	2006-06-22 22:12:04.000000000 +0200
+++ cliplibs/clip-gd/gd/gd_png.c	2010-03-30 07:27:48.000000000 +0200
@@ -122,7 +122,7 @@
     /* first do a quick check that the file really is a PNG image; could
      * have used slightly more general png_sig_cmp() function instead */
     gdGetBuf(sig, 8, infile);
-    if (!png_check_sig(sig, 8))
+    if (png_sig_cmp(sig, 0, 8))
         return NULL;   /* bad signature */
 
 #ifndef PNG_SETJMP_NOT_SUPPORTED
