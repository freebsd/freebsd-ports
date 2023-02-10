--- electron/shell/app/node_main.cc.orig	2023-01-24 16:58:16 UTC
+++ electron/shell/app/node_main.cc
@@ -42,7 +42,7 @@
 #include "content/public/common/content_descriptors.h"
 #endif
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crashpad.h"  // nogncheck
 #include "shell/app/electron_crash_reporter_client.h"
 #include "shell/common/crash_keys.h"
@@ -94,7 +94,7 @@ int SetNodeCliFlags() {
                            node::kDisallowedInEnvironment);
 }
 
-#if defined(MAS_BUILD)
+#if defined(MAS_BUILD) || BUILDFLAG(IS_BSD)
 void SetCrashKeyStub(const std::string& key, const std::string& value) {}
 void ClearCrashKeyStub(const std::string& key) {}
 #endif
@@ -105,7 +105,7 @@ namespace electron {
 
 v8::Local<v8::Value> GetParameters(v8::Isolate* isolate) {
   std::map<std::string, std::string> keys;
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !BUILDFLAG(IS_BSD)
   electron::crash_keys::GetCrashKeys(&keys);
 #endif
   return gin::ConvertToV8(isolate, keys);
@@ -225,7 +225,7 @@ int NodeMain(int argc, char* argv[]) {
       // Setup process.crashReporter in child node processes
       gin_helper::Dictionary reporter = gin::Dictionary::CreateEmpty(isolate);
       reporter.SetMethod("getParameters", &GetParameters);
-#if defined(MAS_BUILD)
+#if defined(MAS_BUILD) || BUILDFLAG(IS_BSD)
       reporter.SetMethod("addExtraParameter", &SetCrashKeyStub);
       reporter.SetMethod("removeExtraParameter", &ClearCrashKeyStub);
 #else
