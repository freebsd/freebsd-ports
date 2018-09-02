--- src/plugins_checker/src/Main.cpp.orig	2018-08-16 13:59:06 UTC
+++ src/plugins_checker/src/Main.cpp
@@ -39,7 +39,7 @@
 #include <ServiceRegistryImpl.h>
 #include <SettingsImpl.h>
 #include <TaskSchedulerImpl.h>
-#include <crash_handler/CrashHandler.h>
+//#include <crash_handler/CrashHandler.h>
 
 #define TR_SETTINGS_ROOT QString("test_runner/")
 
@@ -55,8 +55,10 @@ static void registerCoreServices() {
 
 int main(int argc, char **argv)
 {
+#if 0
     CrashHandler::setupHandler();
     CrashHandler::setSendCrashReports(false);
+#endif
 
     const char* build = QT_VERSION_STR, *runtime = qVersion();
     if (strcmp(build, runtime) > 0){
@@ -141,7 +143,7 @@ int main(int argc, char **argv)
     delete cmdLineRegistry;
     appContext->setCMDLineRegistry(NULL);
 
-    CrashHandler::shutdown();
+    //CrashHandler::shutdown();
 
     return rc;
 }
