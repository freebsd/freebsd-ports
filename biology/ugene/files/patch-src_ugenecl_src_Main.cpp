--- src/ugenecl/src/Main.cpp.orig	2018-08-16 13:59:20 UTC
+++ src/ugenecl/src/Main.cpp
@@ -93,7 +93,7 @@
 #include <ServiceRegistryImpl.h>
 #include <SettingsImpl.h>
 #include <TaskSchedulerImpl.h>
-#include <crash_handler/CrashHandler.h>
+//#include <crash_handler/CrashHandler.h>
 
 // local project imports
 #include "DumpHelpTask.h"
@@ -191,6 +191,7 @@ static void setSearchPaths() {
 
 int main(int argc, char **argv)
 {
+#if 0
     if (CrashHandler::isEnabled()) {
         CrashHandler::setupHandler();
     }
@@ -198,6 +199,7 @@ int main(int argc, char **argv)
     if (qgetenv(ENV_SEND_CRASH_REPORTS) == "0") {
         CrashHandler::setSendCrashReports(false);
     }
+#endif
 
     const char* build = QT_VERSION_STR, *runtime = qVersion();
     if (strcmp(build, runtime) > 0){
@@ -617,7 +619,7 @@ int main(int argc, char **argv)
     delete pwr;
     appContext->setAlignmentAlgorithmsRegistry(NULL);
 
-    CrashHandler::shutdown();
+    //CrashHandler::shutdown();
 
     return rc;
 }
