--- editor/graphics/graphiquefourier.cpp.orig	2020-05-21 08:02:47 UTC
+++ editor/graphics/graphiquefourier.cpp
@@ -30,6 +30,7 @@
 #include <QMenu>
 #include <QFileDialog>
 #include <QPainter>
+#include <QPainterPath>
 
 GraphiqueFourier::GraphiqueFourier(QWidget * parent) : QCustomPlot(parent),
     _fixedTickerX(new QCPAxisTickerFixed()),
