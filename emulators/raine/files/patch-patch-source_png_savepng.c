--- source/png/savepng.c.orig	2005-08-17 12:20:36.000000000 +0200
+++ source/png/savepng.c	2012-05-06 17:19:09.000000000 +0200
@@ -188,7 +188,7 @@
 	goto Error;
 
     /* Set error handling. */
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	/* If we get here, we had a problem reading the file. */
 	goto Error;
     }
