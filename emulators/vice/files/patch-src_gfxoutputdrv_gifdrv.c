--- src/gfxoutputdrv/gifdrv.c.orig	2012-07-25 23:46:05 UTC
+++ src/gfxoutputdrv/gifdrv.c
@@ -114,7 +114,11 @@ static int gifdrv_open(screenshot_t *scr
   if (EGifPutScreenDesc(sdata->fd, screenshot->width, screenshot->height, 8, 0, gif_colors) == GIF_ERROR ||
       EGifPutImageDesc(sdata->fd, 0, 0, screenshot->width, screenshot->height, 0, NULL) == GIF_ERROR)
   {
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+    EGifCloseFile(sdata->fd, NULL);
+#else
     EGifCloseFile(sdata->fd);
+#endif
     VICE_FreeMapObject(gif_colors);
     lib_free(sdata->data);
     lib_free(sdata->ext_filename);
@@ -145,7 +149,11 @@ static int gifdrv_close(screenshot_t *sc
 
     sdata = screenshot->gfxoutputdrv_data;
 
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+    EGifCloseFile(sdata->fd, NULL);
+#else
     EGifCloseFile(sdata->fd);
+#endif
     VICE_FreeMapObject(gif_colors);
 
     /* for some reason giflib will create a file with unexpected
@@ -184,7 +192,11 @@ static char *gifdrv_memmap_ext_filename;
 
 static int gifdrv_close_memmap(void)
 {
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+  EGifCloseFile(gifdrv_memmap_fd, NULL);
+#else
   EGifCloseFile(gifdrv_memmap_fd);
+#endif
   VICE_FreeMapObject(gif_colors);
   lib_free(gifdrv_memmap_ext_filename);
 
@@ -231,7 +243,11 @@ static int gifdrv_open_memmap(const char
   if (EGifPutScreenDesc(gifdrv_memmap_fd, x_size, y_size, 8, 0, gif_colors) == GIF_ERROR ||
       EGifPutImageDesc(gifdrv_memmap_fd, 0, 0, x_size, y_size, 0, NULL) == GIF_ERROR)
   {
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+    EGifCloseFile(gifdrv_memmap_fd, NULL);
+#else
     EGifCloseFile(gifdrv_memmap_fd);
+#endif
     VICE_FreeMapObject(gif_colors);
     lib_free(gifdrv_memmap_ext_filename);
     return -1;
