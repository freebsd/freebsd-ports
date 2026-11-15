--- electron/shell/browser/api/electron_api_safe_storage.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/browser/api/electron_api_safe_storage.cc
@@ -88,7 +88,7 @@ gin::ObjectTemplateBuilder SafeStorage::GetObjectTempl
       .SetMethod("decryptString", &SafeStorage::DecryptString)
       .SetMethod("encryptStringAsync", &SafeStorage::encryptStringAsync)
       .SetMethod("decryptStringAsync", &SafeStorage::decryptStringAsync)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       .SetMethod("getSelectedStorageBackend",
                  &SafeStorage::GetSelectedLinuxBackend)
 #endif
@@ -177,7 +177,7 @@ bool SafeStorage::IsEncryptionAvailable() {
 bool SafeStorage::IsEncryptionAvailable() {
   if (!electron::Browser::Get()->is_ready())
     return false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return OSCrypt::IsEncryptionAvailable() ||
          (use_password_v10_ &&
           static_cast<BrowserProcessImpl*>(g_browser_process)
@@ -197,7 +197,7 @@ v8::Local<v8::Promise> SafeStorage::IsAsyncEncryptionA
     return handle;
   }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (use_password_v10_ && static_cast<BrowserProcessImpl*>(g_browser_process)
                                    ->linux_storage_backend() == "basic_text") {
     promise.Resolve(true);
@@ -220,7 +220,7 @@ void SafeStorage::SetUsePasswordV10(bool use) {
   use_password_v10_ = use;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string SafeStorage::GetSelectedLinuxBackend() {
   if (!electron::Browser::Get()->is_ready())
     return "unknown";
