--- writer.c.orig	2000-09-28 04:22:32.000000000 +0200
+++ writer.c	2010-03-29 16:42:29.000000000 +0200
@@ -31,7 +31,7 @@
   if (png_obj->info->valid & PNG_INFO_PLTE)
     free(png_obj->info->palette);
   if (png_obj->info->valid & PNG_INFO_tRNS)
-    free(png_obj->info->trans);
+    free(png_obj->info->trans_alpha);
 
   png_destroy_write_struct(&png_obj->obj, &png_obj->info);
   free(png_obj);
@@ -67,7 +67,7 @@
 {
   VALUE proc;
 
-  if(png_ptr == NULL || row_number > PNG_MAX_UINT || pass > 7) return;
+  if(png_ptr == NULL || row_number > PNG_UINT_31_MAX || pass > 7) return;
 
   proc = rb_iv_get(cReader, WRITE_STATUS_FN);
 
