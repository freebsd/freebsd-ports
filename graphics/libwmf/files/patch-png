--- src/extra/gd/gd_png.c.orig	2019-02-01 17:51:32 UTC
+++ src/extra/gd/gd_png.c
@@ -138,7 +138,7 @@ gdImageCreateFromPngCtx (gdIOCtx * infile)
   /* first do a quick check that the file really is a PNG image; could
    * have used slightly more general png_sig_cmp() function instead */
   gdGetBuf (sig, 8, infile);
-  if (!png_check_sig (sig, 8))
+  if (png_sig_cmp (sig, 0, 8))
     return NULL;		/* bad signature */
 
 #ifndef PNG_SETJMP_NOT_SUPPORTED
