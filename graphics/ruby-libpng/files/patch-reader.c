--- reader.c.orig	2000-09-28 04:19:46.000000000 +0200
+++ reader.c	2010-03-29 16:43:24.000000000 +0200
@@ -64,7 +64,7 @@
 {
   VALUE proc;
 
-  if(png_ptr == NULL || row_number > PNG_MAX_UINT)
+  if(png_ptr == NULL || row_number > PNG_UINT_31_MAX)
     return;
 
   proc = rb_iv_get(cReader, READ_STATUS_FN);
