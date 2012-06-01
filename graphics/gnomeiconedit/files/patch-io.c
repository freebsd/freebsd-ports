--- src/io.c.orig	2000-06-22 17:24:20.000000000 +0200
+++ src/io.c	2012-05-22 07:40:49.000000000 +0200
@@ -294,7 +294,7 @@
     return FALSE;
   }
   
-  if (setjmp (png_ptr->jmpbuf)) {
+  if (setjmp (png_jmpbuf(png_ptr))) {
     GtkWidget *errorbox;
     
     /* Error handler */
