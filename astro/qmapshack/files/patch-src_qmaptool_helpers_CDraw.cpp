--- src/qmaptool/helpers/CDraw.cpp.orig	2020-05-21 11:11:11 UTC
+++ src/qmaptool/helpers/CDraw.cpp
@@ -24,6 +24,7 @@
 #include <QImage>
 #include <QPointF>
 #include <QtMath>
+#include <QPainterPath>
 
 QPen CDraw::penBorderBlue(QColor(10,10,150,220),2);
 QPen CDraw::penBorderGray(Qt::lightGray,2);
