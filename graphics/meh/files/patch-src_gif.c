--- src/gif.c.orig	2018-10-22 05:11:25 UTC
+++ src/gif.c
@@ -96,11 +96,11 @@ void gif_close(struct image *img){
 
 void gif_close(struct image *img){
 	struct gif_t *g = (struct gif_t *)img;
-#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && (GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1)
+#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && (GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1) || GIFLIB_MAJOR >= 6
 	int ret;
 #endif
 
-#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && (GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1)
+#if defined(GIFLIB_MAJOR) && defined(GIFLIB_MINOR) && (GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1) || GIFLIB_MAJOR >= 6
 	DGifCloseFile(g->gif,&ret);
 	if(ret != GIF_OK) {
 #if defined(GIFLIB_MAJOR) && GIFLIB_MAJOR >= 5
