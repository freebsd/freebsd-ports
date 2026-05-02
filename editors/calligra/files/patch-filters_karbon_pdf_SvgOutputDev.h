--- filters/karbon/pdf/SvgOutputDev.h.orig	2026-04-09 04:19:06 UTC
+++ filters/karbon/pdf/SvgOutputDev.h
@@ -44,7 +44,11 @@ class SvgOutputDev : public OutputDev (public)
     void eoFill(GfxState *state) override;
 
     // text
+#if POPPLER_VERSION_MACRO < QT_VERSION_CHECK(26, 4, 0)
     void drawString(GfxState *state, const GooString *s) override;
+#else
+    void drawString(GfxState *state, const std::string &s) override;
+#endif
 
     // images
     void drawImage(GfxState *state,
