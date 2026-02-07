--- src/qmapshack/helpers/CDraw.cpp.orig	2025-07-04 12:38:57 UTC
+++ src/qmapshack/helpers/CDraw.cpp
@@ -24,6 +24,7 @@
 #include <QPainterPath>
 #include <QPointF>
 #include <QtMath>
+#include <QPainterPath>
 
 QPen CDraw::penBorderBlue(QColor(10, 10, 150, 220), 2);
 QPen CDraw::penBorderGray(Qt::lightGray, 2);
