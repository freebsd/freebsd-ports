--- ext/gd/libgd/gd.h.orig	Wed Apr  9 03:55:56 2003
+++ ext/gd/libgd/gd.h	Sat Jun 28 15:47:56 2003
@@ -446,6 +446,30 @@
 gdImagePtr gdImageCreateFromGifCtx(gdIOCtxPtr in);
 gdImagePtr gdImageCreateFromGifSource(gdSourcePtr in);
 
+void gdImageLzw(gdImagePtr im, FILE *out);
+void* gdImageLzwPtr(gdImagePtr im, int *size);
+void gdImageLzwCtx(gdImagePtr im, gdIOCtxPtr out);
+
+void gdImageBigGif(gdImagePtr im, FILE *out);
+void* gdImageBigGifPtr(gdImagePtr im, int *size);
+void gdImageBigGifCtx(gdImagePtr im, gdIOCtxPtr out);
+
+void gdImageGifAnimBegin(gdImagePtr im, FILE *outFile, int GlobalCM, int Loops);
+void gdImageGifAnimAdd(gdImagePtr im, FILE *outFile, int LocalCM, int LeftOfs, int TopOfs, int Delay, int Disposal);
+void gdImageLzwAnimAdd(gdImagePtr im, FILE *outFile, int LocalCM, int LeftOfs, int TopOfs, int Delay, int Disposal);
+void gdImageBigGifAnimAdd(gdImagePtr im, FILE *outFile, int LocalCM, int LeftOfs, int TopOfs, int Delay, int Disposal);
+void gdImageGifAnimEnd(FILE *outFile);
+void gdImageGifAnimBeginCtx(gdImagePtr im, gdIOCtx *out, int GlobalCM, int Loops);
+void gdImageGifAnimAddCtx(gdImagePtr im, gdIOCtx *out, int LocalCM, int LeftOfs, int TopOfs, int Delay, int Disposal);
+void gdImageLzwAnimAddCtx(gdImagePtr im, gdIOCtx *out, int LocalCM, int LeftOfs, int TopOfs, int Delay, int Disposal);
+void gdImageBigGifAnimAddCtx(gdImagePtr im, gdIOCtx *out, int LocalCM, int LeftOfs, int TopOfs, int Delay, int Disposal);
+void gdImageGifAnimEndCtx(gdIOCtx *out);
+void *gdImageGifAnimBeginPtr(gdImagePtr im, int *size, int GlobalCM, int Loops);
+void *gdImageGifAnimAddPtr(gdImagePtr im, int *size, int LocalCM, int LeftOfs, int TopOfs, int Delay, int Disposal);
+void *gdImageLzwAnimAddPtr(gdImagePtr im, int *size, int LocalCM, int LeftOfs, int TopOfs, int Delay, int Disposal);
+void *gdImageBigGifAnimAddPtr(gdImagePtr im, int *size, int LocalCM, int LeftOfs, int TopOfs, int Delay, int Disposal);
+void *gdImageGifAnimEndPtr(int *size);
+
 /* A custom data sink. For backwards compatibility. Use
 	gdIOCtx instead. */
 /* The sink function must return -1 on error, otherwise the number
@@ -457,6 +481,11 @@
 } gdSink, *gdSinkPtr;
 
 void gdImagePngToSink(gdImagePtr im, gdSinkPtr out);
+
+void gdImageGif (gdImagePtr im, FILE *out);
+void* gdImageGifPtr (gdImagePtr im, int *size);
+void gdImageGifCtx (gdImagePtr im, gdIOCtxPtr out);
+void gdImageGifToSink (gdImagePtr im, gdSinkPtr out);
 
 void gdImageGd(gdImagePtr im, FILE *out);
 void gdImageGd2(gdImagePtr im, FILE *out, int cs, int fmt);
