--- common/gr_texture.c.orig	2000-03-01 05:27:18.000000000 +0100
+++ common/gr_texture.c	2010-03-30 11:19:05.000000000 +0200
@@ -419,7 +419,7 @@
   if (fread (header, 1, PNG_BYTES_TO_CHECK, file) != PNG_BYTES_TO_CHECK) {
     goto ERROR;
   }
-  if (!png_check_sig (header, PNG_BYTES_TO_CHECK)) {
+  if (png_sig_cmp (header, 0, PNG_BYTES_TO_CHECK)) {
     goto ERROR;
   }
 
