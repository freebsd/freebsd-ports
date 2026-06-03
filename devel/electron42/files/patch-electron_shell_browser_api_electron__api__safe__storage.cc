--- electron/shell/browser/api/electron_api_safe_storage.cc.orig	2026-05-08 13:54:01 UTC
+++ electron/shell/browser/api/electron_api_safe_storage.cc
@@ -78,7 +78,7 @@ gin::ObjectTemplateBuilder SafeStorage::GetObjectTempl
       .SetMethod("decryptString", &SafeStorage::DecryptString)
       .SetMethod("encryptStringAsync", &SafeStorage::encryptStringAsync)
       .SetMethod("decryptStringAsync", &SafeStorage::decryptStringAsync)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       .SetMethod("getSelectedStorageBackend",
                  &SafeStorage::GetSelectedLinuxBackend)
 #endif
@@ -145,7 +145,7 @@ bool SafeStorage::IsEncryptionAvailable() {
 bool SafeStorage::IsEncryptionAvailable() {
   if (!electron::Browser::Get()->is_ready())
     return false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return OSCrypt::IsEncryptionAvailable() ||
          (use_password_v10_ &&
           static_cast<BrowserProcessImpl*>(g_browser_process)
@@ -158,7 +158,7 @@ bool SafeStorage::IsAsyncEncryptionAvailable() {
 bool SafeStorage::IsAsyncEncryptionAvailable() {
   if (!electron::Browser::Get()->is_ready())
     return false;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   return is_available_ || (use_password_v10_ &&
                            static_cast<BrowserProcessImpl*>(g_browser_process)
                                    ->linux_storage_backend() == "basic_text");
@@ -171,7 +171,7 @@ void SafeStorage::SetUsePasswordV10(bool use) {
   use_password_v10_ = use;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 std::string SafeStorage::GetSelectedLinuxBackend() {
   if (!electron::Browser::Get()->is_ready())
     return "unknown";
