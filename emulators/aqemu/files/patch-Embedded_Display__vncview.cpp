--- Embedded_Display/vncview.cpp.orig	2010-02-26 13:40:40 UTC
+++ Embedded_Display/vncview.cpp
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
