--- gd.h.orig	Sat Oct 30 14:54:58 2004
+++ gd.h	Fri Nov  5 20:47:19 2004
@@ -291,6 +291,10 @@
    /* Deprecated in favor of gdImageCreateFromPngCtx */
 BGD_DECLARE(gdImagePtr) gdImageCreateFromPngSource (gdSourcePtr in);
 
+#ifdef __FreeBSD__
+BGD_DECLARE(gdImagePtr) gdImageCreateFromGifSource(gdSourcePtr in);
+#endif
+
 BGD_DECLARE(gdImagePtr) gdImageCreateFromGd (FILE * in);
 BGD_DECLARE(gdImagePtr) gdImageCreateFromGdCtx (gdIOCtxPtr in);
 BGD_DECLARE(gdImagePtr) gdImageCreateFromGdPtr (int size, void *data);
@@ -591,6 +595,16 @@
 BGD_DECLARE(void *) gdImageGifAnimAddPtr(gdImagePtr im, int *size, int LocalCM, int LeftOfs, int TopOfs, int Delay, int Disposal, gdImagePtr previm);
 BGD_DECLARE(void *) gdImageGifAnimEndPtr(int *size);
 
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
@@ -604,6 +618,10 @@
   gdSink, *gdSinkPtr;
 
 BGD_DECLARE(void) gdImagePngToSink (gdImagePtr im, gdSinkPtr out);
+
+#ifdef __FreeBSD__
+BGD_DECLARE(void) gdImageGifToSink(gdImagePtr im, gdSinkPtr out);
+#endif
 
 BGD_DECLARE(void) gdImageGd (gdImagePtr im, FILE * out);
 BGD_DECLARE(void) gdImageGd2 (gdImagePtr im, FILE * out, int cs, int fmt);
