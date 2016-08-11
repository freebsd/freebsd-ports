--- src/ugenecl/src/Main.cpp.orig	2016-03-31 12:22:19 UTC
+++ src/ugenecl/src/Main.cpp
@@ -94,7 +94,7 @@
 #include <ServiceRegistryImpl.h>
 #include <SettingsImpl.h>
 #include <TaskSchedulerImpl.h>
-#include <crash_handler/CrashHandler.h>
+//#include <crash_handler/CrashHandler.h>
 
 // local project imports
 #include "DumpHelpTask.h"
@@ -192,9 +192,11 @@ static void setSearchPaths() {
 
 int main(int argc, char **argv)
 {
+#if 0
     if (CrashHandler::isEnabled()) {
         CrashHandler::setupHandler();
     }
+#endif
     const char* build = QT_VERSION_STR, *runtime = qVersion();
     if (strcmp(build, runtime) > 0){
         printf("Installed Qt version must be %s or greater \r\n", QT_VERSION_STR);
@@ -617,7 +619,7 @@ int main(int argc, char **argv)
     delete pwr;
     appContext->setAlignmentAlgorithmsRegistry(NULL);
 
-    CrashHandler::shutdown();
+    //CrashHandler::shutdown();
 
     return rc;
 }
