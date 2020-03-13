--- electron/shell/app/node_main.cc.orig	2019-12-13 19:48:14 UTC
+++ electron/shell/app/node_main.cc
@@ -32,7 +32,7 @@
 
 namespace electron {
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
 void AddExtraParameter(const std::string& key, const std::string& value) {
   crash_reporter::CrashReporter::GetInstance()->AddExtraParameter(key, value);
 }
@@ -104,7 +104,7 @@ int NodeMain(int argc, char* argv[]) {
     auto reporter = mate::Dictionary::CreateEmpty(gin_env.isolate());
     reporter.SetMethod("start", &crash_reporter::CrashReporter::StartInstance);
 
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
     reporter.SetMethod("addExtraParameter", &AddExtraParameter);
     reporter.SetMethod("removeExtraParameter", &RemoveExtraParameter);
 #endif
