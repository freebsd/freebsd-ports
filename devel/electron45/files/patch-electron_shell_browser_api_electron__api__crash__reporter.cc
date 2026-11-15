--- electron/shell/browser/api/electron_api_crash_reporter.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/browser/api/electron_api_crash_reporter.cc
@@ -38,7 +38,7 @@
 #include "shell/common/process_util.h"
 #include "shell/common/thread_restrictions.h"
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crashpad.h"  // nogncheck
 #include "components/crash/core/browser/crash_upload_list_crashpad.h"  // nogncheck
 #include "components/crash/core/common/crash_key.h"
@@ -72,7 +72,7 @@ namespace electron::api::crash_reporter {
 
 namespace electron::api::crash_reporter {
 
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
 namespace {
 
 void NoOp() {}
@@ -143,7 +143,7 @@ void Start(const std::string& submit_url,
            const std::map<std::string, std::string>& extra,
            bool is_node_process) {
   TRACE_EVENT0("electron", "crash_reporter::Start");
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   if (g_crash_reporter_initialized)
     return;
   g_crash_reporter_initialized = true;
@@ -193,7 +193,7 @@ namespace {
 
 namespace {
 
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
 v8::Local<v8::Value> GetUploadedReports(v8::Isolate* isolate) {
   return v8::Array::New(isolate);
 }
@@ -325,7 +325,7 @@ void SetUploadToServer(bool upload) {
 }
 
 void SetUploadToServer(bool upload) {
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   ElectronCrashReporterClient::Get()->SetCollectStatsConsent(upload);
   // Reads the consent set above back through IsRunningUnattended().
   crash_reporter::SetUploadConsent(upload);
@@ -333,7 +333,7 @@ bool GetUploadToServer() {
 }
 
 bool GetUploadToServer() {
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
   return false;
 #else
   return ElectronCrashReporterClient::Get()->GetCollectStatsConsent();
@@ -342,7 +342,7 @@ v8::Local<v8::Value> GetParameters(v8::Isolate* isolat
 
 v8::Local<v8::Value> GetParameters(v8::Isolate* isolate) {
   std::map<std::string, std::string> keys;
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   electron::crash_keys::GetCrashKeys(&keys);
 #endif
   return gin::ConvertToV8(isolate, keys);
@@ -356,7 +356,7 @@ void Initialize(v8::Local<v8::Object> exports,
   gin_helper::Dictionary dict(isolate, exports);
   dict.SetMethod<&Start>("start");
   dict.SetMethod<&GetLastCrashReport>("getLastCrashReport");
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
   dict.SetMethod<&electron::api::crash_reporter::NoOp>("addExtraParameter");
   dict.SetMethod<&electron::api::crash_reporter::NoOp>("removeExtraParameter");
 #else
