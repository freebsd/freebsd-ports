--- src/qmapshack/helpers/CDraw.cpp.orig	2021-05-24 09:18:08 UTC
+++ src/qmapshack/helpers/CDraw.cpp
@@ -25,6 +25,7 @@
 #include <QPainterPath>
 #include <QPointF>
 #include <QtMath>
+#include <QPainterPath>
 
 QPen CDraw::penBorderBlue(QColor(10, 10, 150, 220), 2);
 QPen CDraw::penBorderGray(Qt::lightGray, 2);
