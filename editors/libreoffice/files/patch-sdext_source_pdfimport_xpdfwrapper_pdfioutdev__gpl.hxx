--- sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.hxx.orig	2026-04-17 11:34:08 UTC
+++ sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.hxx
@@ -260,7 +260,9 @@ void setDefaultCTM(const std::array<double, 6> &pMat) 
                               double originX, double originY,
                               CharCode code, int nBytes, Unicode *u, int uLen) override;
 #endif
-#if POPPLER_CHECK_VERSION(0, 64, 0)
+#if POPPLER_CHECK_VERSION(26, 4, 0)
+        virtual void drawString(GfxState *state, const std::string &s) override;
+#elif POPPLER_CHECK_VERSION(0, 64, 0)
         virtual void drawString(GfxState *state, const GooString *s) override;
 #else
         virtual void drawString(GfxState *state, GooString *s) override;
