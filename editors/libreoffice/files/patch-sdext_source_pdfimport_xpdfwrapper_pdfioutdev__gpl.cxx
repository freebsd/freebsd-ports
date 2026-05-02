--- sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx.orig	2026-04-17 11:12:42 UTC
+++ sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx
@@ -1114,7 +1114,9 @@ void PDFOutDev::drawChar(GfxState *state, double x, do
     printf( "\n" );
 }
 
-#if POPPLER_CHECK_VERSION(0, 64, 0)
+#if POPPLER_CHECK_VERSION(26, 4, 0)
+void PDFOutDev::drawString(GfxState*, const std::string& /*s*/)
+#elif POPPLER_CHECK_VERSION(0, 64, 0)
 void PDFOutDev::drawString(GfxState*, const GooString* /*s*/)
 #else
 void PDFOutDev::drawString(GfxState*, GooString* /*s*/)
