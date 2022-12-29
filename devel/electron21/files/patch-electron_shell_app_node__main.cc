--- electron/shell/app/node_main.cc.orig	2022-05-18 15:31:32 UTC
+++ electron/shell/app/node_main.cc
@@ -38,7 +38,7 @@
 #include "chrome/child/v8_crashpad_support_win.h"
 #endif
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crashpad.h"  // nogncheck
 #include "shell/app/electron_crash_reporter_client.h"
 #include "shell/browser/api/electron_api_crash_reporter.h"
@@ -91,7 +91,7 @@ int SetNodeCliFlags() {
                            node::kDisallowedInEnvironment);
 }
 
-#if defined(MAS_BUILD)
+#if defined(MAS_BUILD) || BUILDFLAG(IS_BSD)
 void SetCrashKeyStub(const std::string& key, const std::string& value) {}
 void ClearCrashKeyStub(const std::string& key) {}
 #endif
@@ -131,7 +131,7 @@ void CrashReporterStart(gin_helper::Dictionary options
 
 v8::Local<v8::Value> GetParameters(v8::Isolate* isolate) {
   std::map<std::string, std::string> keys;
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !BUILDFLAG(IS_BSD)
   electron::crash_keys::GetCrashKeys(&keys);
 #endif
   return gin::ConvertToV8(isolate, keys);
@@ -144,7 +144,7 @@ int NodeMain(int argc, char* argv[]) {
   v8_crashpad_support::SetUp();
 #endif
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !BUILDFLAG(IS_BSD)
   ElectronCrashReporterClient::Create();
 #endif
 
@@ -152,7 +152,7 @@ int NodeMain(int argc, char* argv[]) {
   crash_reporter::InitializeCrashpad(false, "node");
 #endif
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !BUILDFLAG(IS_BSD)
   crash_keys::SetCrashKeysFromCommandLine(
       *base::CommandLine::ForCurrentProcess());
   crash_keys::SetPlatformCrashKey();
@@ -230,7 +230,7 @@ int NodeMain(int argc, char* argv[]) {
 #endif
 
       reporter.SetMethod("getParameters", &GetParameters);
-#if defined(MAS_BUILD)
+#if defined(MAS_BUILD) || BUILDFLAG(IS_BSD)
       reporter.SetMethod("addExtraParameter", &SetCrashKeyStub);
       reporter.SetMethod("removeExtraParameter", &ClearCrashKeyStub);
 #else
