--- electron/shell/browser/api/electron_api_safe_storage.h.orig	2026-06-29 20:35:15 UTC
+++ electron/shell/browser/api/electron_api_safe_storage.h
@@ -78,7 +78,7 @@ class SafeStorage final : public gin_helper::Deprecate
   v8::Local<v8::Promise> decryptStringAsync(v8::Isolate* isolate,
                                             v8::Local<v8::Value> buffer);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string GetSelectedLinuxBackend();
 #endif
 
