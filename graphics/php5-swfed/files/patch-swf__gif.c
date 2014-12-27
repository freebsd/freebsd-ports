--- swf_gif.c.orig	2014-02-10 02:32:16 UTC
+++ swf_gif.c
@@ -132,7 +132,11 @@ gifconv_gif2lossless(unsigned char *gif_
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
@@ -252,7 +256,11 @@ gifconv_lossless2gif(void *image_data,
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
@@ -292,7 +300,11 @@ gifconv_lossless2gif(void *image_data,
     }
 
     GifFile->SavedImages[0].RasterBits = gif_image_data;
+#if GIFLIB_MAJOR >= 5
+    GifFile->SColorMap = GifMakeMapObject(ColorCount, Colors);
+#else
     GifFile->SColorMap = MakeMapObject(ColorCount, Colors);
+#endif
     EGifSpew(GifFile); // XXX
 
     free(gif_image_data);
