--- electron/shell/browser/api/electron_api_safe_storage.cc.orig	2024-10-22 02:29:46 UTC
+++ electron/shell/browser/api/electron_api_safe_storage.cc
@@ -19,7 +19,7 @@ bool IsEncryptionAvailable() {
 bool use_password_v10 = false;
 
 bool IsEncryptionAvailable() {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Calling IsEncryptionAvailable() before the app is ready results in a crash
   // on Linux.
   // Refs: https://github.com/electron/electron/issues/32206.
@@ -38,7 +38,7 @@ void SetUsePasswordV10(bool use) {
   use_password_v10 = use;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string GetSelectedLinuxBackend() {
   if (!electron::Browser::Get()->is_ready())
     return "unknown";
@@ -135,7 +135,7 @@ void Initialize(v8::Local<v8::Object> exports,
   gin_helper::Dictionary dict(isolate, exports);
   dict.SetMethod("decryptString", &DecryptString);
   dict.SetMethod("encryptString", &EncryptString);
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   dict.SetMethod("getSelectedStorageBackend", &GetSelectedLinuxBackend);
 #endif
   dict.SetMethod("isEncryptionAvailable", &IsEncryptionAvailable);
