--- rwpng.c.orig	2006-06-15 11:39:29.000000000 +0200
+++ rwpng.c	2010-03-29 15:35:32.000000000 +0200
@@ -77,7 +77,7 @@
      * have used slightly more general png_sig_cmp() function instead */
 
     fread(sig, 1, 8, infile);
-    if (!png_check_sig(sig, 8)) {
+    if (png_sig_cmp(sig, 0, 8)) {
         mainprog_ptr->retval = 21;   /* bad signature */
         return mainprog_ptr->retval;
     }
