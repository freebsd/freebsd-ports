--- electron/shell/app/node_main.cc.orig	2021-04-20 23:32:33 UTC
+++ electron/shell/app/node_main.cc
@@ -38,7 +38,7 @@
 #include "chrome/child/v8_crashpad_support_win.h"
 #endif
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
 #include "components/crash/core/app/crashpad.h"  // nogncheck
 #include "shell/app/electron_crash_reporter_client.h"
 #include "shell/browser/api/electron_api_crash_reporter.h"
@@ -86,7 +86,7 @@ void SetNodeCliFlags() {
   ProcessGlobalArgs(&args, nullptr, &errors, node::kDisallowedInEnvironment);
 }
 
-#if defined(MAS_BUILD)
+#if defined(MAS_BUILD) || defined(OS_BSD)
 void SetCrashKeyStub(const std::string& key, const std::string& value) {}
 void ClearCrashKeyStub(const std::string& key) {}
 #endif
@@ -126,7 +126,7 @@ void CrashReporterStart(gin_helper::Dictionary options
 
 v8::Local<v8::Value> GetParameters(v8::Isolate* isolate) {
   std::map<std::string, std::string> keys;
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
   electron::crash_keys::GetCrashKeys(&keys);
 #endif
   return gin::ConvertToV8(isolate, keys);
@@ -139,7 +139,7 @@ int NodeMain(int argc, char* argv[]) {
   v8_crashpad_support::SetUp();
 #endif
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
   ElectronCrashReporterClient::Create();
 #endif
 
@@ -147,7 +147,7 @@ int NodeMain(int argc, char* argv[]) {
   crash_reporter::InitializeCrashpad(false, "node");
 #endif
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
   crash_keys::SetCrashKeysFromCommandLine(
       *base::CommandLine::ForCurrentProcess());
   crash_keys::SetPlatformCrashKey();
@@ -221,7 +221,7 @@ int NodeMain(int argc, char* argv[]) {
 #endif
 
       reporter.SetMethod("getParameters", &GetParameters);
-#if defined(MAS_BUILD)
+#if defined(MAS_BUILD) || defined(OS_BSD)
       reporter.SetMethod("addExtraParameter", &SetCrashKeyStub);
       reporter.SetMethod("removeExtraParameter", &ClearCrashKeyStub);
 #else
