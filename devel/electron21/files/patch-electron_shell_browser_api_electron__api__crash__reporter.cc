--- electron/shell/browser/api/electron_api_crash_reporter.cc.orig	2023-01-24 08:00:52 UTC
+++ electron/shell/browser/api/electron_api_crash_reporter.cc
@@ -30,7 +30,7 @@
 #include "shell/common/gin_helper/dictionary.h"
 #include "shell/common/node_includes.h"
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !BUILDFLAG(IS_BSD)
 #include "components/crash/core/app/crashpad.h"  // nogncheck
 #include "components/crash/core/browser/crash_upload_list_crashpad.h"  // nogncheck
 #include "components/crash/core/common/crash_key.h"
@@ -66,7 +66,7 @@ bool g_crash_reporter_initialized = false;
 
 namespace electron::api::crash_reporter {
 
-#if defined(MAS_BUILD)
+#if defined(MAS_BUILD) || BUILDFLAG(IS_BSD)
 namespace {
 
 void NoOp() {}
@@ -133,7 +133,7 @@ void Start(const std::string& submit_url,
            const std::map<std::string, std::string>& extra,
            bool is_node_process) {
   TRACE_EVENT0("electron", "crash_reporter::Start");
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !BUILDFLAG(IS_BSD)
   if (g_crash_reporter_initialized)
     return;
   g_crash_reporter_initialized = true;
@@ -196,7 +196,7 @@ void Start(const std::string& submit_url,
 
 namespace {
 
-#if defined(MAS_BUILD)
+#if defined(MAS_BUILD) || BUILDFLAG(IS_BSD)
 void GetUploadedReports(
     v8::Isolate* isolate,
     base::OnceCallback<void(v8::Local<v8::Value>)> callback) {
@@ -253,13 +253,13 @@ v8::Local<v8::Value> GetUploadedReports(v8::Isolate* i
 #endif
 
 void SetUploadToServer(bool upload) {
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !BUILDFLAG(IS_BSD)
   ElectronCrashReporterClient::Get()->SetCollectStatsConsent(upload);
 #endif
 }
 
 bool GetUploadToServer() {
-#if defined(MAS_BUILD)
+#if defined(MAS_BUILD) || BUILDFLAG(IS_BSD)
   return false;
 #else
   return ElectronCrashReporterClient::Get()->GetCollectStatsConsent();
@@ -268,7 +268,7 @@ bool GetUploadToServer() {
 
 v8::Local<v8::Value> GetParameters(v8::Isolate* isolate) {
   std::map<std::string, std::string> keys;
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !BUILDFLAG(IS_BSD)
   electron::crash_keys::GetCrashKeys(&keys);
 #endif
   return gin::ConvertToV8(isolate, keys);
@@ -280,7 +280,7 @@ void Initialize(v8::Local<v8::Object> exports,
                 void* priv) {
   gin_helper::Dictionary dict(context->GetIsolate(), exports);
   dict.SetMethod("start", &electron::api::crash_reporter::Start);
-#if defined(MAS_BUILD)
+#if defined(MAS_BUILD) || BUILDFLAG(IS_BSD)
   dict.SetMethod("addExtraParameter", &electron::api::crash_reporter::NoOp);
   dict.SetMethod("removeExtraParameter", &electron::api::crash_reporter::NoOp);
 #else
