Fix build with Clang 8:

../dspdfviewer.cpp:311:48: error: empty expression statement has no effect; remove unnecessary ';' to silence this warning [-Werror,-Wextra-semi-stmt]
  QSize newSize = window.getPreviewImageSize();;
                                               ^

--- dspdfviewer.cpp.orig	2016-09-13 13:18:47 UTC
+++ dspdfviewer.cpp
@@ -308,7 +308,7 @@ RenderingIdentifier DSPDFViewer::toRenderIdent(unsigne
 
 RenderingIdentifier DSPDFViewer::toThumbnailRenderIdent(unsigned int pageNumber, PDFViewerWindow& window)
 {
-  QSize newSize = window.getPreviewImageSize();;
+  QSize newSize = window.getPreviewImageSize();
   static QSize thumbnailSize;
   if ( thumbnailSize != newSize ) {
     DEBUGOUT << "Thumbnail size changed from" << thumbnailSize << "to" << newSize;
