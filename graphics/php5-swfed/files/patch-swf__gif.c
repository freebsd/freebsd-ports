--- swf_gif.c.orig	2014-02-10 02:32:16 UTC
+++ swf_gif.c
@@ -132,14 +132,22 @@ gifconv_gif2lossless(unsigned char *gif_
     gif_buff.data = gif_data;
     gif_buff.data_len = gif_data_len;
     gif_buff.data_offset = 0;
+#if GIFLIB_MAJOR >= 5
+    GifFile = DGifOpen(& gif_buff, gif_data_read_func, NULL);
+#else
     GifFile = DGifOpen(& gif_buff, gif_data_read_func);
+#endif
     if (GifFile == NULL) {
         fprintf(stderr, "gifconv_gif2lossless: can't open GIFFile\n");
         return NULL;
     }
     if (DGifSlurp(GifFile) == GIF_ERROR) {
         fprintf(stderr, "gifconv_gif2lossless: DGifSlurp failed\n");
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+        DGifCloseFile(GifFile, NULL);
+#else
         DGifCloseFile(GifFile);
+#endif
         return NULL;
     }
     Image = GifFile->SavedImages[0];
@@ -152,7 +160,11 @@ gifconv_gif2lossless(unsigned char *gif_
     bpp = ColorMap->BitsPerPixel;
     if (bpp > 8) {
         fprintf(stderr, "gifconv_gif2lossless: bpp=%d not implemented. accept only bpp <= 8\n", bpp);
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+        DGifCloseFile(GifFile, NULL);
+#else
         DGifCloseFile(GifFile);
+#endif
         return NULL;
     }
     palette_num = ColorMap->ColorCount;
@@ -216,7 +228,11 @@ gifconv_gif2lossless(unsigned char *gif_
      * destruct
      */
     if (GifFile) {
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+        DGifCloseFile(GifFile, NULL);
+#else
         DGifCloseFile(GifFile);
+#endif
     }
     return image_data;
 }
@@ -252,7 +268,11 @@ gifconv_lossless2gif(void *image_data,
     gif_buff.data = NULL;
     gif_buff.data_len = 0;
     gif_buff.data_offset = 0;
+#if GIFLIB_MAJOR >= 5
+    GifFile = EGifOpen(& gif_buff, gif_data_write_func, NULL);
+#else
     GifFile = EGifOpen(& gif_buff, gif_data_write_func);
+#endif
     if (GifFile == NULL) {
         fprintf(stderr, "gifconv_lossless2gif: can't open GIFFile\n");
         return NULL;
@@ -292,13 +312,21 @@ gifconv_lossless2gif(void *image_data,
     }
 
     GifFile->SavedImages[0].RasterBits = gif_image_data;
+#if GIFLIB_MAJOR >= 5
+    GifFile->SColorMap = GifMakeMapObject(ColorCount, Colors);
+#else
     GifFile->SColorMap = MakeMapObject(ColorCount, Colors);
+#endif
     EGifSpew(GifFile); // XXX
 
     free(gif_image_data);
 
     if (GifFile) {
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+        EGifCloseFile(GifFile, NULL);
+#else
         EGifCloseFile(GifFile);
+#endif
     }
     *length = gif_buff.data_offset;
     return gif_buff.data;
