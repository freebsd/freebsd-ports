--- electron/shell/renderer/api/electron_api_crash_reporter_renderer.cc.orig	2021-01-26 05:34:17 UTC
+++ electron/shell/renderer/api/electron_api_crash_reporter_renderer.cc
@@ -6,7 +6,7 @@
 #include "shell/common/gin_helper/dictionary.h"
 #include "shell/common/node_includes.h"
 
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
 #include "shell/common/crash_keys.h"
 #endif
 
@@ -14,13 +14,13 @@ namespace {
 
 v8::Local<v8::Value> GetParameters(v8::Isolate* isolate) {
   std::map<std::string, std::string> keys;
-#if !defined(MAS_BUILD)
+#if !defined(MAS_BUILD) && !defined(OS_BSD)
   electron::crash_keys::GetCrashKeys(&keys);
 #endif
   return gin::ConvertToV8(isolate, keys);
 }
 
-#if defined(MAS_BUILD)
+#if defined(MAS_BUILD) || defined(OS_BSD)
 void SetCrashKeyStub(const std::string& key, const std::string& value) {}
 void ClearCrashKeyStub(const std::string& key) {}
 #endif
@@ -30,7 +30,7 @@ void Initialize(v8::Local<v8::Object> exports,
                 v8::Local<v8::Context> context,
                 void* priv) {
   gin_helper::Dictionary dict(context->GetIsolate(), exports);
-#if defined(MAS_BUILD)
+#if defined(MAS_BUILD) || defined(OS_BSD)
   dict.SetMethod("addExtraParameter", &SetCrashKeyStub);
   dict.SetMethod("removeExtraParameter", &ClearCrashKeyStub);
 #else
