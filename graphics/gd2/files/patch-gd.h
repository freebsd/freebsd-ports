--- gd.h.orig	Thu Apr 25 14:15:24 2002
+++ gd.h	Thu Apr 25 12:43:55 2002
@@ -201,6 +201,10 @@
 
 gdImagePtr gdImageCreateFromPngSource(gdSourcePtr in);
 
+gdImagePtr gdImageCreateFromGif(FILE *fd);
+gdImagePtr gdImageCreateFromGifCtx(gdIOCtxPtr in);
+gdImagePtr gdImageCreateFromGifSource(gdSourcePtr in);
+
 gdImagePtr gdImageCreateFromGd(FILE *in);
 gdImagePtr gdImageCreateFromGdCtx(gdIOCtxPtr in);
 
@@ -251,12 +255,26 @@
 char *gdImageStringFT(gdImage *im, int *brect, int fg, char *fontlist,
                 double ptsize, double angle, int x, int y, char *string);
 
+typedef struct {
+	int flags; /* for future expansion logical OR of gdFTEX_ values */
+	double linespacing; /* fine tune line spacing for '\n' */
+} gdFTStringExtra, *gdFTStringExtraPtr;
+#define gdFTEX_LINESPACE 1
+
+/* FreeType 2 text output with fine tuning */
+char *
+gdImageStringFTEx(gdImage * im, int *brect, int fg, char * fontlist,
+		double ptsize, double angle, int x, int y, char * string,
+		gdFTStringExtraPtr strex);
+
+
 /* Point type for use in polygon drawing. */
 typedef struct {
 	int x, y;
 } gdPoint, *gdPointPtr;
 
 void gdImagePolygon(gdImagePtr im, gdPointPtr p, int n, int c);
+void gdImageOpenPolygon(gdImagePtr im, gdPointPtr p, int n, int c);
 void gdImageFilledPolygon(gdImagePtr im, gdPointPtr p, int n, int c);
 
 /* These functions still work with truecolor images, 
@@ -347,6 +365,14 @@
 /* Best to free this memory with gdFree(), not free() */
 void *gdImageJpegPtr(gdImagePtr im, int *size, int quality);
 
+void gdImageLzw(gdImagePtr im, FILE *out);
+void* gdImageLzwPtr(gdImagePtr im, int *size);
+void gdImageLzwCtx(gdImagePtr im, gdIOCtxPtr out);
+
+void gdImageBigGif(gdImagePtr im, FILE *out);
+void* gdImageBigGifPtr(gdImagePtr im, int *size);
+void gdImageBigGifCtx(gdImagePtr im, gdIOCtxPtr out);
+
 /* A custom data sink. For backwards compatibility. Use
 	gdIOCtx instead. */
 /* The sink function must return -1 on error, otherwise the number
@@ -358,6 +384,11 @@
 } gdSink, *gdSinkPtr;
 
 void gdImagePngToSink(gdImagePtr im, gdSinkPtr out);
+
+void gdImageGif(gdImagePtr im, FILE *out);
+void* gdImageGifPtr(gdImagePtr im, int *size);
+void gdImageGifCtx(gdImagePtr im, gdIOCtxPtr out);
+void gdImageGifToSink(gdImagePtr im, gdSinkPtr out);
 
 void gdImageGd(gdImagePtr im, FILE *out);
 void gdImageGd2(gdImagePtr im, FILE *out, int cs, int fmt);
