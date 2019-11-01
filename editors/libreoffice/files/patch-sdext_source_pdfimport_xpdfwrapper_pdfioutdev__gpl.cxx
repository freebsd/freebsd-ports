--- sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx.orig	2019-10-27 14:16:14 UTC
+++ sdext/source/pdfimport/xpdfwrapper/pdfioutdev_gpl.cxx
@@ -866,7 +866,7 @@ void PDFOutDev::eoClip(GfxState *state)
 void PDFOutDev::drawChar(GfxState *state, double x, double y,
                          double dx, double dy,
                          double originX, double originY,
-                         CharCode, int /*nBytes*/, Unicode *u, int uLen)
+                         CharCode, int /*nBytes*/, const Unicode *u, int uLen)
 {
     assert(state);
 
@@ -982,7 +982,7 @@ void PDFOutDev::drawImageMask(GfxState* pState, Object
 void PDFOutDev::drawImage(GfxState*, Object*, Stream* str,
                           int width, int height, GfxImageColorMap* colorMap,
                           poppler_bool /*interpolate*/,
-                          int* maskColors, poppler_bool /*inlineImg*/ )
+                          const int* maskColors, poppler_bool /*inlineImg*/ )
 {
     if (m_bSkipImages)
         return;
@@ -1004,12 +1004,12 @@ void PDFOutDev::drawImage(GfxState*, Object*, Stream* 
         {
             GfxRGB aMinRGB;
             colorMap->getColorSpace()->getRGB(
-                reinterpret_cast<GfxColor*>(maskColors),
+                reinterpret_cast<const GfxColor*>(maskColors),
                 &aMinRGB );
 
             GfxRGB aMaxRGB;
             colorMap->getColorSpace()->getRGB(
-                reinterpret_cast<GfxColor*>(maskColors)+gfxColorMaxComps,
+                reinterpret_cast<const GfxColor*>(maskColors)+gfxColorMaxComps,
                 &aMaxRGB );
 
             aMaskBuf.push_back( colToByte(aMinRGB.r) );
