--- src/ui/popwidget.cpp.orig	2008-05-18 08:46:46.000000000 +0800
+++ src/ui/popwidget.cpp	2008-06-21 08:54:12.000000000 +0800
@@ -20,13 +20,13 @@
 
 #include "popwidget.h"
 
-#include <qpixmap.h>
-#include <qapplication.h>
+#include <QPixmap>
+#include <QApplication>
 #if (QT_VERSION>=300)
-#include <qdesktopwidget.h>
+#include <QDesktopWidget>
 #endif
-#include <qtimer.h>
-#include <qlabel.h>
+#include <QTimer>
+#include <QLabel>
 
 #include <QMouseEvent>
 #include <QPalette>
