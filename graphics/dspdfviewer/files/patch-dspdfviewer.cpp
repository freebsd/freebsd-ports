Fix build with Clang 8:

../dspdfviewer.cpp:311:48: error: empty expression statement has no effect; remove unnecessary ';' to silence this warning [-Werror,-Wextra-semi-stmt]
  QSize newSize = window.getPreviewImageSize();;
                                               ^

--- dspdfviewer.cpp.orig	2016-09-13 13:18:47 UTC
+++ dspdfviewer.cpp
@@ -292,10 +292,10 @@ void DSPDFViewer::sendAllClockSignals() const
   emit presentationClockUpdate(presentationClock());
 }
 
-QTime DSPDFViewer::timeSince(const QTime& startPoint) const
+QTime DSPDFViewer::timeSince(const QElapsedTimer& startPoint) const
 {
   QTime result(0,0);
-  result = result.addMSecs(startPoint.elapsed());
+  result = result.addMSecs(static_cast<int>(startPoint.elapsed()));
   return result;
 }
 
@@ -308,7 +308,7 @@ RenderingIdentifier DSPDFViewer::toRenderIdent(unsigne
 
 RenderingIdentifier DSPDFViewer::toThumbnailRenderIdent(unsigned int pageNumber, PDFViewerWindow& window)
 {
-  QSize newSize = window.getPreviewImageSize();;
+  QSize newSize = window.getPreviewImageSize();
   static QSize thumbnailSize;
   if ( thumbnailSize != newSize ) {
     DEBUGOUT << "Thumbnail size changed from" << thumbnailSize << "to" << newSize;
