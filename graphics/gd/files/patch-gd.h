--- gd.h.orig	Sat Jul 17 20:02:38 2004
+++ gd.h	Wed Aug 25 13:38:59 2004
@@ -278,6 +278,10 @@
    /* Deprecated in favor of gdImageCreateFromPngCtx */
 BGD_DECLARE(gdImagePtr) gdImageCreateFromPngSource (gdSourcePtr in);
 
+#ifdef __FreeBSD__
+BGD_DECLARE(gdImagePtr) gdImageCreateFromGifSource(gdSourcePtr in);
+#endif
+
 BGD_DECLARE(gdImagePtr) gdImageCreateFromGd (FILE * in);
 BGD_DECLARE(gdImagePtr) gdImageCreateFromGdCtx (gdIOCtxPtr in);
 BGD_DECLARE(gdImagePtr) gdImageCreateFromGdPtr (int size, void *data);
@@ -407,6 +411,9 @@
   gdPoint, *gdPointPtr;
 
 BGD_DECLARE(void) gdImagePolygon (gdImagePtr im, gdPointPtr p, int n, int c);
+#ifdef __FreeBSD__
+BGD_DECLARE(void) gdImageOpenPolygon (gdImagePtr im, gdPointPtr p, int n, int c);
+#endif
 BGD_DECLARE(void) gdImageFilledPolygon (gdImagePtr im, gdPointPtr p, int n, int c);
 
 /* These functions still work with truecolor images, 
@@ -517,6 +524,16 @@
 /* Best to free this memory with gdFree(), not free() */
 BGD_DECLARE(void *) gdImageJpegPtr (gdImagePtr im, int *size, int quality);
 
+#ifdef __FreeBSD__
+BGD_DECLARE(void) gdImageLzw(gdImagePtr im, FILE *out);
+BGD_DECLARE(void *) gdImageLzwPtr(gdImagePtr im, int *size);
+BGD_DECLARE(void) gdImageLzwCtx(gdImagePtr im, gdIOCtxPtr out);
+
+BGD_DECLARE(void) gdImageBigGif(gdImagePtr im, FILE *out);
+BGD_DECLARE(void *) gdImageBigGifPtr(gdImagePtr im, int *size);
+BGD_DECLARE(void) gdImageBigGifCtx(gdImagePtr im, gdIOCtxPtr out);
+#endif
+
 /* A custom data sink. For backwards compatibility. Use
 	gdIOCtx instead. */
 /* The sink function must return -1 on error, otherwise the number
@@ -530,6 +547,10 @@
   gdSink, *gdSinkPtr;
 
 BGD_DECLARE(void) gdImagePngToSink (gdImagePtr im, gdSinkPtr out);
+
+#ifdef __FreeBSD__
+BGD_DECLARE(void) gdImageGifToSink(gdImagePtr im, gdSinkPtr out);
+#endif
 
 BGD_DECLARE(void) gdImageGd (gdImagePtr im, FILE * out);
 BGD_DECLARE(void) gdImageGd2 (gdImagePtr im, FILE * out, int cs, int fmt);
