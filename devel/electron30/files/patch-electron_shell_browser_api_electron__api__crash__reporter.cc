--- electron/shell/browser/api/electron_api_crash_reporter.cc.orig	2024-09-05 10:01:25 UTC
+++ electron/shell/browser/api/electron_api_crash_reporter.cc
@@ -31,7 +31,7 @@
 #include "shell/common/process_util.h"
 #include "shell/common/thread_restrictions.h"
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crashpad.h"  // nogncheck
 #include "components/crash/core/browser/crash_upload_list_crashpad.h"  // nogncheck
 #include "components/crash/core/common/crash_key.h"
@@ -66,7 +66,7 @@ namespace electron::api::crash_reporter {
 
 namespace electron::api::crash_reporter {
 
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
 namespace {
 
 void NoOp() {}
@@ -137,7 +137,7 @@ void Start(const std::string& submit_url,
            const std::map<std::string, std::string>& extra,
            bool is_node_process) {
   TRACE_EVENT0("electron", "crash_reporter::Start");
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   if (g_crash_reporter_initialized)
     return;
   g_crash_reporter_initialized = true;
@@ -183,7 +183,7 @@ namespace {
 
 namespace {
 
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
 void GetUploadedReports(
     v8::Isolate* isolate,
     base::OnceCallback<void(v8::Local<v8::Value>)> callback) {
@@ -239,13 +239,13 @@ void SetUploadToServer(bool upload) {
 #endif
 
 void SetUploadToServer(bool upload) {
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   ElectronCrashReporterClient::Get()->SetCollectStatsConsent(upload);
 #endif
 }
 
 bool GetUploadToServer() {
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
   return false;
 #else
   return ElectronCrashReporterClient::Get()->GetCollectStatsConsent();
@@ -254,7 +254,7 @@ v8::Local<v8::Value> GetParameters(v8::Isolate* isolat
 
 v8::Local<v8::Value> GetParameters(v8::Isolate* isolate) {
   std::map<std::string, std::string> keys;
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   electron::crash_keys::GetCrashKeys(&keys);
 #endif
   return gin::ConvertToV8(isolate, keys);
@@ -266,7 +266,7 @@ void Initialize(v8::Local<v8::Object> exports,
                 void* priv) {
   gin_helper::Dictionary dict(context->GetIsolate(), exports);
   dict.SetMethod("start", &electron::api::crash_reporter::Start);
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
   dict.SetMethod("addExtraParameter", &electron::api::crash_reporter::NoOp);
   dict.SetMethod("removeExtraParameter", &electron::api::crash_reporter::NoOp);
 #else
