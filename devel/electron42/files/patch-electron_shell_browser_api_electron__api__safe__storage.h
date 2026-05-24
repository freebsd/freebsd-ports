--- electron/shell/browser/api/electron_api_safe_storage.h.orig	2026-05-19 01:17:05 UTC
+++ electron/shell/browser/api/electron_api_safe_storage.h
@@ -77,7 +77,7 @@ class SafeStorage final : public gin_helper::Deprecate
   v8::Local<v8::Promise> decryptStringAsync(v8::Isolate* isolate,
                                             v8::Local<v8::Value> buffer);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string GetSelectedLinuxBackend();
 #endif
 
