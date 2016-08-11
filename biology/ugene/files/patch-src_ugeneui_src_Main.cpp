--- src/ugeneui/src/Main.cpp.orig	2016-03-31 12:22:18 UTC
+++ src/ugeneui/src/Main.cpp
@@ -134,7 +134,7 @@
 #include <ServiceRegistryImpl.h>
 #include <SettingsImpl.h>
 #include <TaskSchedulerImpl.h>
-#include <crash_handler/CrashHandler.h>
+//#include <crash_handler/CrashHandler.h>
 
 #include "app_settings/AppSettingsGUIImpl.h"
 #include "app_settings/logview_settings/LogSettingsGUIController.h"
@@ -343,9 +343,11 @@ void fixMacFonts() {
 
 int main(int argc, char **argv)
 {
+#if 0
     if (CrashHandler::isEnabled()) {
         CrashHandler::setupHandler();
     }
+#endif
 
     QT_REQUIRE_VERSION( argc, argv, QT_VERSION_STR );
 
@@ -966,7 +968,7 @@ int main(int argc, char **argv)
     }
 
     UgeneUpdater::onClose();
-    CrashHandler::shutdown();
+    //CrashHandler::shutdown();
 
     return rc;
 }
