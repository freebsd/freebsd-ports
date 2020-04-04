Fix build with Qt5-5.14

--- Annotation.h.orig	2020-04-04 11:09:27 UTC
+++ Annotation.h
@@ -1,4 +1,5 @@
 #include <QColor>
+#include <QImage>
 #include <QList>
 #include <QPointF>
 #include <QPolygonF>
