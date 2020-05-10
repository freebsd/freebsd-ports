--- src/ugeneui/src/Main.cpp.orig	2018-08-16 13:59:19 UTC
+++ src/ugeneui/src/Main.cpp
@@ -136,7 +136,7 @@
 #include <ServiceRegistryImpl.h>
 #include <SettingsImpl.h>
 #include <TaskSchedulerImpl.h>
-#include <crash_handler/CrashHandler.h>
+//#include <crash_handler/CrashHandler.h>
 
 #include "app_settings/AppSettingsGUIImpl.h"
 #include "app_settings/logview_settings/LogSettingsGUIController.h"
@@ -353,6 +353,7 @@ void fixMacFonts() {
 
 int main(int argc, char **argv)
 {
+#if 0
     if (CrashHandler::isEnabled()) {
         CrashHandler::setupHandler();
     }
@@ -360,6 +361,7 @@ int main(int argc, char **argv)
     if (qgetenv(ENV_SEND_CRASH_REPORTS) == "0") {
         CrashHandler::setSendCrashReports(false);
     }
+#endif
 
     QT_REQUIRE_VERSION( argc, argv, QT_VERSION_STR );
 
@@ -973,7 +975,7 @@ int main(int argc, char **argv)
     }
 
     UgeneUpdater::onClose();
-    CrashHandler::shutdown();
+    //CrashHandler::shutdown();
 
     return rc;
 }
