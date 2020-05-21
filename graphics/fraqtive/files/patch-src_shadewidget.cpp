--- src/shadewidget.cpp.orig	2020-05-21 07:06:17 UTC
+++ src/shadewidget.cpp
@@ -20,6 +20,7 @@
 
 #include <QPainter>
 #include <QPaintEvent>
+#include <QPainterPath>
 #include <QToolTip>
 
 ShadeWidget::ShadeWidget( QWidget* parent ) : QWidget( parent ),
