--- frmts/pdf/pdfdataset.cpp.orig	2019-11-06 21:52:23.571566000 -0700
+++ frmts/pdf/pdfdataset.cpp	2019-11-06 21:54:10.765908000 -0700
@@ -205,7 +205,11 @@
         virtual void drawChar(GfxState *state, double x, double y,
                               double dx, double dy,
                               double originX, double originY,
-                              CharCode code, int nBytes, Unicode *u, int uLen) override
+                              CharCode code, int nBytes,
+#if POPPLER_MAJOR_VERSION >= 1 || POPPLER_MINOR_VERSION >= 82
+                              const
+#endif
+                              Unicode *u, int uLen) override
         {
             if (bEnableText)
                 SplashOutputDev::drawChar(state, x, y, dx, dy,
@@ -265,7 +269,11 @@
 
         virtual void drawImage(GfxState *state, Object *ref, Stream *str,
                                int width, int height, GfxImageColorMap *colorMap,
-                               GBool interpolate, int *maskColors, GBool inlineImg) override
+                               GBool interpolate,
+#if POPPLER_MAJOR_VERSION >= 1 || POPPLER_MINOR_VERSION >= 82
+                              const
+#endif
+                               int *maskColors, GBool inlineImg) override
         {
             if (bEnableBitmap)
                 SplashOutputDev::drawImage(state, ref, str,
