--- Embedded_Display/vncview.cpp~	2012-05-21 15:10:07.000000000 -0300
+++ Embedded_Display/vncview.cpp	2012-05-21 15:10:25.000000000 -0300
@@ -23,6 +23,11 @@
 
 #include "vncview.h"
 
+#include <QApplication>
+#include <QImage>
+#include <QPainter>
+#include <QMouseEvent>
+
 #ifdef QTONLY
     #include <QMessageBox>
     #include <QInputDialog>
@@ -38,11 +43,6 @@
     #include <KXMLGUIClient>
 #endif
 
-#include <QApplication>
-#include <QImage>
-#include <QPainter>
-#include <QMouseEvent>
-
 // Definition of key modifier mask constants
 #define KMOD_Alt_R 	0x01
 #define KMOD_Alt_L 	0x02
