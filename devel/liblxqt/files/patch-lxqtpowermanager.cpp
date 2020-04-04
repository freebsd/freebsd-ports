Fix compatiblity with Qt5.14

--- lxqtpowermanager.cpp.orig	2020-04-04 08:10:45 UTC
+++ lxqtpowermanager.cpp
@@ -31,6 +31,7 @@
 #include <QMessageBox>
 #include <QApplication>
 #include <QDesktopWidget>
+#include <QFile>
 #include <QtDebug>
 #include "lxqttranslator.h"
 #include "lxqtglobals.h"
