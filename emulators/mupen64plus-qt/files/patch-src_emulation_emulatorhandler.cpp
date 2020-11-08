--- src/emulation/emulatorhandler.cpp.orig	2020-11-08 17:32:57 UTC
+++ src/emulation/emulatorhandler.cpp
@@ -38,8 +38,8 @@
 #include <QFile>
 #include <QMessageBox>
 
-#include <quazip5/quazip.h>
-#include <quazip5/quazipfile.h>
+#include <quazip/quazip.h>
+#include <quazip/quazipfile.h>
 
 
 EmulatorHandler::EmulatorHandler(QWidget *parent) : QObject(parent)
