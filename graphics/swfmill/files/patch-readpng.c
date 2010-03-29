--- src/swft/readpng.c.orig	2006-07-20 15:57:17.000000000 +0200
+++ src/swft/readpng.c	2010-03-29 16:19:53.000000000 +0200
@@ -69,7 +69,7 @@
      * have used slightly more general png_sig_cmp() function instead */
 
     fread(sig, 1, 8, infile);
-    if (!png_check_sig(sig, 8))
+    if (png_sig_cmp(sig, 0, 8))
         return 1;   /* bad signature */
 
 
