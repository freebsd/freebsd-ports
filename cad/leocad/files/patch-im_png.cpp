--- common/im_png.cpp.orig	2000-09-16 19:18:01.000000000 +0200
+++ common/im_png.cpp	2012-04-27 08:02:21.000000000 +0200
@@ -34,7 +34,7 @@
     return NULL;
 
   fread(sig, 1, 8, f);
-  if (!png_check_sig(sig, 8))
+  if (png_sig_cmp(sig, 0, 8))
   {
     fclose(f);
     return NULL;	// bad signature
@@ -55,7 +55,7 @@
     return NULL;	// out of memory
   }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
   {
     png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
     fclose(f);
@@ -69,7 +69,7 @@
   png_get_IHDR(png_ptr, info_ptr, &width, &height, &bit_depth, &color_type,
 	       NULL, NULL, NULL);
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
   {
     png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
     fclose(f);
@@ -80,7 +80,7 @@
   {
     png_get_bKGD(png_ptr, info_ptr, &pBackground);
 
-    if (setjmp (png_ptr->jmpbuf))
+    if (setjmp (png_jmpbuf(png_ptr)))
     {
       png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
       fclose(f);
@@ -113,7 +113,7 @@
   }
   else
   {
-    if (setjmp (png_ptr->jmpbuf))
+    if (setjmp (png_jmpbuf(png_ptr)))
     {
       png_destroy_read_struct(&png_ptr, &info_ptr, NULL);
       fclose(f);
@@ -283,7 +283,7 @@
     return false;
   }
 
-  if (setjmp(png_ptr->jmpbuf))
+  if (setjmp(png_jmpbuf(png_ptr)))
   {
     png_destroy_write_struct(&png_ptr,  (png_infopp)NULL);
     fclose(fp);
