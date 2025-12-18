Fix build with Qt 6.10.1. The QString::arg() method no longer accepts
implicit conversions. [1]

[1] https://doc.qt.io/qt-6/qstring.html#arg-2

--- src/utils/starrating.cpp.orig	2025-09-21 21:11:29 UTC
+++ src/utils/starrating.cpp
@@ -104,7 +104,7 @@ void StarRating::paint(QPainter* painter, const QRect&
                                  .arg(m_maxCount)
                                  .arg(mode == EditMode::Editable ? 1 : 0)
                                  .arg(rect.width())
-                                 .arg(alignment);
+                                 .arg(alignment.toInt());
 
     QPixmap pixmap;
     if(!QPixmapCache::find(cacheKey, &pixmap)) {
