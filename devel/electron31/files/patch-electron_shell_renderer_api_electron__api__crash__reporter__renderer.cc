--- electron/shell/renderer/api/electron_api_crash_reporter_renderer.cc.orig	2023-02-06 19:29:11 UTC
+++ electron/shell/renderer/api/electron_api_crash_reporter_renderer.cc
@@ -6,7 +6,7 @@
 #include "shell/common/gin_helper/dictionary.h"
 #include "shell/common/node_includes.h"
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 #include "shell/common/crash_keys.h"
 #endif
 
@@ -14,13 +14,13 @@ namespace {
 
 v8::Local<v8::Value> GetParameters(v8::Isolate* isolate) {
   std::map<std::string, std::string> keys;
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   electron::crash_keys::GetCrashKeys(&keys);
 #endif
   return gin::ConvertToV8(isolate, keys);
 }
 
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
 void SetCrashKeyStub(const std::string& key, const std::string& value) {}
 void ClearCrashKeyStub(const std::string& key) {}
 #endif
@@ -30,7 +30,7 @@ void Initialize(v8::Local<v8::Object> exports,
                 v8::Local<v8::Context> context,
                 void* priv) {
   gin_helper::Dictionary dict(context->GetIsolate(), exports);
-#if IS_MAS_BUILD()
+#if IS_MAS_BUILD() || BUILDFLAG(IS_BSD)
   dict.SetMethod("addExtraParameter", &SetCrashKeyStub);
   dict.SetMethod("removeExtraParameter", &ClearCrashKeyStub);
 #else
