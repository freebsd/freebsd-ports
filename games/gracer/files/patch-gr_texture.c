--- common/gr_texture.c.orig	2000-03-01 05:27:18.000000000 +0100
+++ common/gr_texture.c	2012-05-03 20:29:17.000000000 +0200
@@ -419,7 +419,7 @@
   if (fread (header, 1, PNG_BYTES_TO_CHECK, file) != PNG_BYTES_TO_CHECK) {
     goto ERROR;
   }
-  if (!png_check_sig (header, PNG_BYTES_TO_CHECK)) {
+  if (png_sig_cmp (header, 0, PNG_BYTES_TO_CHECK)) {
     goto ERROR;
   }
 
@@ -431,7 +431,7 @@
   if (!info_ptr) {
     goto ERROR;
   }
-  if (setjmp (png_ptr->jmpbuf)) {
+  if (setjmp (png_jmpbuf(png_ptr))) {
     goto ERROR;
   }
   png_init_io (png_ptr, file);
