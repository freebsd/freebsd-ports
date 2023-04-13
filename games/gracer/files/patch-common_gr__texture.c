--- common/gr_texture.c.orig	2000-03-01 04:27:18 UTC
+++ common/gr_texture.c
@@ -274,7 +274,11 @@ read_gif_file (GrTexture *texture, char *filename)
   int index;
   int width, height;
 
+#if GIFLIB_MAJOR >= 5
+  file = DGifOpenFileName (filename, NULL);
+#else
   file = DGifOpenFileName (filename);
+#endif
   if (!file)
     return -1;
 
@@ -419,7 +423,7 @@ read_png_file (GrTexture *texture, char *filename)
   if (fread (header, 1, PNG_BYTES_TO_CHECK, file) != PNG_BYTES_TO_CHECK) {
     goto ERROR;
   }
-  if (!png_check_sig (header, PNG_BYTES_TO_CHECK)) {
+  if (png_sig_cmp (header, 0, PNG_BYTES_TO_CHECK)) {
     goto ERROR;
   }
 
@@ -431,7 +435,7 @@ read_png_file (GrTexture *texture, char *filename)
   if (!info_ptr) {
     goto ERROR;
   }
-  if (setjmp (png_ptr->jmpbuf)) {
+  if (setjmp (png_jmpbuf(png_ptr))) {
     goto ERROR;
   }
   png_init_io (png_ptr, file);
