--- src/ugeneui/src/Main.cpp.orig	2020-06-17 15:14:26 UTC
+++ src/ugeneui/src/Main.cpp
@@ -151,7 +151,7 @@
 #include <ServiceRegistryImpl.h>
 #include <SettingsImpl.h>
 #include <TaskSchedulerImpl.h>
-#include <crash_handler/CrashHandler.h>
+//#include <crash_handler/CrashHandler.h>
 
 #include "app_settings/AppSettingsGUIImpl.h"
 #include "app_settings/logview_settings/LogSettingsGUIController.h"
@@ -403,6 +403,7 @@ void fixMacFonts() {
 }    // namespace
 
 int main(int argc, char **argv) {
+#if 0
     if (CrashHandler::isEnabled()) {
         CrashHandler::setupHandler();
     }
@@ -410,6 +411,7 @@ int main(int argc, char **argv) {
     if (qgetenv(ENV_SEND_CRASH_REPORTS) == "0") {
         CrashHandler::setSendCrashReports(false);
     }
+#endif
 
     QT_REQUIRE_VERSION(argc, argv, QT_VERSION_STR);
 
@@ -422,7 +424,7 @@ int main(int argc, char **argv) {
     //QApplication app(argc, argv);
     GApplication app(argc, argv);
 
-#ifdef Q_OS_LINUX
+#ifdef Q_OS_UNIX
     QPixmap pixmap(":/ugene/images/originals/ugene_128.png");
     app.setWindowIcon(pixmap);
 #endif
@@ -1088,7 +1090,7 @@ int main(int argc, char **argv) {
     }
 
     UgeneUpdater::onClose();
-    CrashHandler::shutdown();
+    //CrashHandler::shutdown();
 
     return rc;
 }
