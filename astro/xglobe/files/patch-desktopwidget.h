--- desktopwidget.h.orig	1998-12-09 18:16:54 UTC
+++ desktopwidget.h
@@ -23,6 +23,8 @@
 #include <qwidget.h>
 #include <qpixmap.h>
 #include <qpainter.h>
+//Added by qt3to4:
+#include <QPaintEvent>
 
 class DesktopWidget : public QWidget
 {
