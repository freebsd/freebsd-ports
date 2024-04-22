--- electron/shell/app/node_main.cc.orig	2024-03-06 14:57:56 UTC
+++ electron/shell/app/node_main.cc
@@ -48,7 +48,7 @@
 #include "shell/common/mac/codesign_util.h"
 #endif
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crashpad.h"  // nogncheck
 #include "shell/app/electron_crash_reporter_client.h"
 #include "shell/common/crash_keys.h"
@@ -99,7 +99,7 @@ bool UnsetHijackableEnvs(base::Environment* env) {
 }
 #endif
 
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
 void SetCrashKeyStub(const std::string& key, const std::string& value) {}
 void ClearCrashKeyStub(const std::string& key) {}
 #endif
@@ -110,7 +110,7 @@ v8::Local<v8::Value> GetParameters(v8::Isolate* isolat
 
 v8::Local<v8::Value> GetParameters(v8::Isolate* isolate) {
   std::map<std::string, std::string> keys;
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   electron::crash_keys::GetCrashKeys(&keys);
 #endif
   return gin::ConvertToV8(isolate, keys);
@@ -270,7 +270,7 @@ int NodeMain(int argc, char* argv[]) {
       // Setup process.crashReporter in child node processes
       auto reporter = gin_helper::Dictionary::CreateEmpty(isolate);
       reporter.SetMethod("getParameters", &GetParameters);
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
       reporter.SetMethod("addExtraParameter", &SetCrashKeyStub);
       reporter.SetMethod("removeExtraParameter", &ClearCrashKeyStub);
 #else
