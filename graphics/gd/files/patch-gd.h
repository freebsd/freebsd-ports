--- gd.h	Thu Jan 16 11:28:09 2003
+++ gd.h	Mon Mar 24 16:26:14 2003
@@ -209,4 +209,8 @@
   gdImagePtr gdImageCreateFromPngSource (gdSourcePtr in);
 
+  gdImagePtr gdImageCreateFromGif(FILE *fd);
+  gdImagePtr gdImageCreateFromGifCtx(gdIOCtxPtr in);
+  gdImagePtr gdImageCreateFromGifSource(gdSourcePtr in);
+
   gdImagePtr gdImageCreateFromGd (FILE * in);
   gdImagePtr gdImageCreateFromGdCtx (gdIOCtxPtr in);
@@ -300,4 +304,5 @@
 
   void gdImagePolygon (gdImagePtr im, gdPointPtr p, int n, int c);
+  void gdImageOpenPolygon(gdImagePtr im, gdPointPtr p, int n, int c);
   void gdImageFilledPolygon (gdImagePtr im, gdPointPtr p, int n, int c);
 
@@ -395,4 +400,13 @@
   void *gdImageJpegPtr (gdImagePtr im, int *size, int quality);
 
+  void gdImageLzw(gdImagePtr im, FILE *out);
+  void* gdImageLzwPtr(gdImagePtr im, int *size);
+  void gdImageLzwCtx(gdImagePtr im, gdIOCtxPtr out);
+
+  void gdImageBigGif(gdImagePtr im, FILE *out);
+  void* gdImageBigGifPtr(gdImagePtr im, int *size);
+  void gdImageBigGifCtx(gdImagePtr im, gdIOCtxPtr out);
+
+
 /* A custom data sink. For backwards compatibility. Use
 	gdIOCtx instead. */
@@ -408,4 +422,9 @@
 
   void gdImagePngToSink (gdImagePtr im, gdSinkPtr out);
+
+  void gdImageGif(gdImagePtr im, FILE *out);
+  void* gdImageGifPtr(gdImagePtr im, int *size);
+  void gdImageGifCtx(gdImagePtr im, gdIOCtxPtr out);
+  void gdImageGifToSink(gdImagePtr im, gdSinkPtr out);
 
   void gdImageGd (gdImagePtr im, FILE * out);
