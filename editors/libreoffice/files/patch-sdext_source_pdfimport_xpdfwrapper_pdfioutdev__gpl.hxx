--- sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.hxx.orig	2019-10-27 14:16:24 UTC
+++ sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.hxx
@@ -232,10 +232,18 @@ namespace pdfi
         virtual void eoClip(GfxState *state) override;
 
         //----- text drawing
+#if POPPLER_CHECK_VERSION(0, 82, 0)
         virtual void drawChar(GfxState *state, double x, double y,
                               double dx, double dy,
                               double originX, double originY,
+                              CharCode code, int nBytes, const Unicode *u, int uLen) override;
+#else
+        virtual void drawChar(GfxState *state, double x, double y,
+                              double dx, double dy,
+                              double originX, double originY,
                               CharCode code, int nBytes, Unicode *u, int uLen) override;
+#endif
+
 #if POPPLER_CHECK_VERSION(0, 64, 0)
         virtual void drawString(GfxState *state, const GooString *s) override;
 #else
@@ -248,10 +256,17 @@ namespace pdfi
                                    int width, int height, poppler_bool invert,
                                    poppler_bool interpolate,
                                    poppler_bool inlineImg) override;
+#if POPPLER_CHECK_VERSION(0, 82, 0)
         virtual void drawImage(GfxState *state, Object *ref, Stream *str,
                                int width, int height, GfxImageColorMap *colorMap,
                                poppler_bool interpolate,
+                               const int* maskColors, poppler_bool inlineImg) override;
+#else
+        virtual void drawImage(GfxState *state, Object *ref, Stream *str,
+                               int width, int height, GfxImageColorMap *colorMap,
+                               poppler_bool interpolate,
                                int* maskColors, poppler_bool inlineImg) override;
+#endif
         virtual void drawMaskedImage(GfxState *state, Object *ref, Stream *str,
                                      int width, int height,
                                      GfxImageColorMap *colorMap,
