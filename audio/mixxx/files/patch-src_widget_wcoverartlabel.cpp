--- src/widget/wcoverartlabel.cpp.orig	2025-07-04 17:25:50 UTC
+++ src/widget/wcoverartlabel.cpp
@@ -70,7 +70,7 @@ void WCoverArtLabel::setPixmapAndResize(const QPixmap&
         m_fullSizeCover = px;
         setPixmap(m_loadedCover);
     }
-#if (QT_VERSION >= QT_VERSION_CHECK(5, 15, 0))
+#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
     QSize newSize = pixmap().size() / devicePixelRatioF();
 #else
     QSize newSize = pixmap()->size() / devicePixelRatioF();
@@ -92,7 +92,11 @@ void WCoverArtLabel::setMaxSize(const QSize newSize) {
     // Skip resizing the pixmap and label if the pixmap already fits.
     // Check if we got more space in one dimension and don't need it
     // for the other.
+#if (QT_VERSION >= QT_VERSION_CHECK(6, 0, 0))
     const QSize pixmapSize = pixmap().size() / devicePixelRatioF();
+#else
+    const QSize pixmapSize = pixmap()->size() / devicePixelRatioF();
+#endif
     if (m_pixmapSizeMax == pixmapSize ||
             (m_pixmapSizeMax.height() == pixmapSize.height() &&
                     m_pixmapSizeMax.width() > pixmapSize.width()) ||
