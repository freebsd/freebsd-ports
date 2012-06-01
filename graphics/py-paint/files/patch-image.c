--- image.c.orig	2004-02-16 10:57:56.000000000 +0100
+++ image.c	2012-05-05 07:40:54.000000000 +0200
@@ -129,7 +129,7 @@
 	set_error(PyExc_RuntimeError, "could not create info struct");
 	return NULL;
     }
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	fclose(fp);
 	png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
 	set_error(PyExc_RuntimeError, "error building image");
@@ -233,7 +233,7 @@
 	set_error(PyExc_RuntimeError, "could not create info struct");
 	goto error;
     }
-    if (setjmp(png_ptr->jmpbuf)) {
+    if (setjmp(png_jmpbuf(png_ptr))) {
 	set_error(PyExc_RuntimeError, "error building image");
 	goto error;
     }
