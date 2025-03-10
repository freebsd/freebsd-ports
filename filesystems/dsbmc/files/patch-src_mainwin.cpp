Add Qt5.14 compatibility 

--- src/mainwin.cpp.orig	2020-04-04 08:18:00 UTC
+++ src/mainwin.cpp
@@ -27,6 +27,8 @@
 #include <QSpinBox>
 #include <QMenuBar>
 #include <QMessageBox>
+#include <QMoveEvent>
+#include <QResizeEvent>
 #include <QStatusBar>
 #include <errno.h>
 
