diff --git a/hphp/runtime/ext/ext_image.cpp b/hphp/runtime/ext/ext_image.cpp
index 3f471a3..7793ee3 100644
--- a/hphp/runtime/ext/ext_image.cpp
+++ hphp/runtime/ext/ext_image.cpp
@@ -2351,11 +2351,11 @@ static const char php_sig_gd2[3] = {'g', 'd', '2'};
    ** This way you gain a lot of flexibilty about how this package
    ** reads a wbmp file.
  */
-static int getmbi(int (*getin) (void *in), void *in) {
+static int getmbi(gdIOCtx *ctx) {
   int i, mbi = 0;
 
   do {
-    i = getin (in);
+    i = (ctx->getC)(ctx);
     if (i < 0)
       return (-1);
     mbi = (mbi << 7) | (i & 0x7f);
@@ -2369,11 +2369,11 @@ static int getmbi(int (*getin) (void *in), void *in) {
    ** Skips the ExtHeader. Not needed for the moment
    **
  */
-int skipheader (int (*getin) (void *in), void *in) {
+int skipheader (gdIOCtx *ctx) {
   int i;
 
   do {
-    i = getin (in);
+    i = (ctx->getC)(ctx);
     if (i < 0) return (-1);
   }
   while (i & 0x80);
@@ -2404,8 +2404,8 @@ static int _php_image_type (char data[8]) {
     gdIOCtx *io_ctx;
     io_ctx = gdNewDynamicCtxEx(8, data, 0);
     if (io_ctx) {
-      if (getmbi((int(*)(void *)) gdGetC, io_ctx) == 0 &&
-          skipheader((int(*)(void *)) gdGetC, io_ctx) == 0 ) {
+      if (getmbi(io_ctx) == 0 &&
+          skipheader(io_ctx) == 0 ) {
 #if HAVE_LIBGD204
         io_ctx->gd_free(io_ctx);
 #else
@@ -4200,8 +4200,8 @@ bool f_imagefilter(CResRef image, int filtertype,
   (src->trueColor?gdImageGetTrueColorPixel:gdImageGetPixel)
 #endif
 
-static int gdImageConvolution(gdImagePtr src, float filter[3][3],
-                              float filter_div, float offset) {
+static int hphp_gdImageConvolution(gdImagePtr src, float filter[3][3],
+                                   float filter_div, float offset) {
   int x, y, i, j, new_a;
   float new_r, new_g, new_b;
   int new_pxl, pxl=0;
@@ -4290,7 +4290,7 @@ bool f_imageconvolution(CResRef image, CArrRef matrix,
       }
     }
   }
-  if (gdImageConvolution(im_src, mtx, div, offset)) {
+  if (hphp_gdImageConvolution(im_src, mtx, div, offset)) {
     return true;
   } else {
     return false;
