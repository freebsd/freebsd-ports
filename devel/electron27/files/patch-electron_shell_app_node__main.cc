--- electron/shell/app/node_main.cc.orig	2023-10-20 08:29:17 UTC
+++ electron/shell/app/node_main.cc
@@ -42,7 +42,7 @@
 #include "content/public/common/content_descriptors.h"
 #endif
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crashpad.h"  // nogncheck
 #include "shell/app/electron_crash_reporter_client.h"
 #include "shell/common/crash_keys.h"
@@ -77,7 +77,7 @@ void ExitIfContainsDisallowedFlags(const std::vector<s
   }
 }
 
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
 void SetCrashKeyStub(const std::string& key, const std::string& value) {}
 void ClearCrashKeyStub(const std::string& key) {}
 #endif
@@ -88,7 +88,7 @@ namespace electron {
 
 v8::Local<v8::Value> GetParameters(v8::Isolate* isolate) {
   std::map<std::string, std::string> keys;
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   electron::crash_keys::GetCrashKeys(&keys);
 #endif
   return gin::ConvertToV8(isolate, keys);
@@ -224,7 +224,7 @@ int NodeMain(int argc, char* argv[]) {
       // Setup process.crashReporter in child node processes
       gin_helper::Dictionary reporter = gin::Dictionary::CreateEmpty(isolate);
       reporter.SetMethod("getParameters", &GetParameters);
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
       reporter.SetMethod("addExtraParameter", &SetCrashKeyStub);
       reporter.SetMethod("removeExtraParameter", &ClearCrashKeyStub);
 #else
