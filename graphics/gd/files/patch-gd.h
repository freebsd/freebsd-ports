--- gd.h.orig	Thu Jan 15 18:42:10 2004
+++ gd.h	Wed Mar 17 16:52:30 2004
@@ -273,6 +273,12 @@
    /* Deprecated in favor of gdImageCreateFromPngCtx */
    BGD_EXPORT gdImagePtr gdImageCreateFromPngSource (gdSourcePtr in);
 
+#ifdef __FreeBSD__
+   BGD_EXPORT gdImagePtr gdImageCreateFromGif(FILE *fd);
+   BGD_EXPORT gdImagePtr gdImageCreateFromGifCtx(gdIOCtxPtr in);
+   BGD_EXPORT gdImagePtr gdImageCreateFromGifSource(gdSourcePtr in);
+#endif
+
    BGD_EXPORT gdImagePtr gdImageCreateFromGd (FILE * in);
    BGD_EXPORT gdImagePtr gdImageCreateFromGdCtx (gdIOCtxPtr in);
    BGD_EXPORT gdImagePtr gdImageCreateFromGdPtr (int size, void *data);
@@ -397,6 +403,9 @@
   gdPoint, *gdPointPtr;
 
    BGD_EXPORT void gdImagePolygon (gdImagePtr im, gdPointPtr p, int n, int c);
+#ifdef __FreeBSD__
+   BGD_EXPORT void gdImageOpenPolygon(gdImagePtr im, gdPointPtr p, int n, int c);
+#endif
    BGD_EXPORT void gdImageFilledPolygon (gdImagePtr im, gdPointPtr p, int n, int c);
 
 /* These functions still work with truecolor images, 
@@ -498,6 +507,17 @@
 /* Best to free this memory with gdFree(), not free() */
   BGD_EXPORT void *gdImageJpegPtr (gdImagePtr im, int *size, int quality);
 
+#ifdef __FreeBSD__
+  BGD_EXPORT void gdImageLzw(gdImagePtr im, FILE *out);
+  BGD_EXPORT void* gdImageLzwPtr(gdImagePtr im, int *size);
+  BGD_EXPORT void gdImageLzwCtx(gdImagePtr im, gdIOCtxPtr out);
+
+  BGD_EXPORT void gdImageBigGif(gdImagePtr im, FILE *out);
+  BGD_EXPORT void* gdImageBigGifPtr(gdImagePtr im, int *size);
+  BGD_EXPORT void gdImageBigGifCtx(gdImagePtr im, gdIOCtxPtr out);
+#endif
+
+
 /* A custom data sink. For backwards compatibility. Use
 	gdIOCtx instead. */
 /* The sink function must return -1 on error, otherwise the number
@@ -511,6 +531,13 @@
   gdSink, *gdSinkPtr;
 
    BGD_EXPORT void gdImagePngToSink (gdImagePtr im, gdSinkPtr out);
+
+#ifdef __FreeBSD__
+   BGD_EXPORT void gdImageGif(gdImagePtr im, FILE *out);
+   BGD_EXPORT void* gdImageGifPtr(gdImagePtr im, int *size);
+   BGD_EXPORT void gdImageGifCtx(gdImagePtr im, gdIOCtxPtr out);
+   BGD_EXPORT void gdImageGifToSink(gdImagePtr im, gdSinkPtr out);
+#endif
 
    BGD_EXPORT void gdImageGd (gdImagePtr im, FILE * out);
    BGD_EXPORT void gdImageGd2 (gdImagePtr im, FILE * out, int cs, int fmt);
