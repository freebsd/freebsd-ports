Fix build with Qt5-5.14

--- PrintWidget.cpp.orig	2020-04-04 10:57:54 UTC
+++ PrintWidget.cpp
@@ -1,5 +1,6 @@
 #include "PrintWidget.h"
 #include <QGraphicsProxyWidget>
+#include <QImage>
 #include <QPushButton>
 #include <QtConcurrent>
 
