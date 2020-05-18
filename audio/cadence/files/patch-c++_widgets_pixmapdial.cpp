--- c++/widgets/pixmapdial.cpp.orig	2020-05-18 18:12:49 UTC
+++ c++/widgets/pixmapdial.cpp
@@ -22,6 +22,7 @@
 #include <QtCore/QTimer>
 #include <QtGui/QPainter>
 #include <QtGui/QPaintEvent>
+#include <QtGui/QPainterPath>
 
 PixmapDial::PixmapDial(QWidget* parent)
     : QDial(parent),
