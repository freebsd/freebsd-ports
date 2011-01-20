--- desktopwidget.h.orig	1998-12-09 10:16:54.000000000 -0800
+++ desktopwidget.h	2011-01-18 14:22:52.000000000 -0800
@@ -23,6 +23,8 @@
 #include <qwidget.h>
 #include <qpixmap.h>
 #include <qpainter.h>
+//Added by qt3to4:
+#include <QPaintEvent>
 
 class DesktopWidget : public QWidget
 {
