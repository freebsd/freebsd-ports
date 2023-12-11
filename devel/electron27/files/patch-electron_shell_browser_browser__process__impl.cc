--- electron/shell/browser/browser_process_impl.cc.orig	2023-10-20 08:29:17 UTC
+++ electron/shell/browser/browser_process_impl.cc
@@ -309,7 +309,7 @@ const std::string& BrowserProcessImpl::GetSystemLocale
   return system_locale_;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void BrowserProcessImpl::SetLinuxStorageBackend(
     os_crypt::SelectedLinuxBackend selected_backend) {
   switch (selected_backend) {
@@ -337,7 +337,7 @@ void BrowserProcessImpl::SetLinuxStorageBackend(
 const std::string& BrowserProcessImpl::GetLinuxStorageBackend() const {
   return selected_linux_storage_backend_;
 }
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 void BrowserProcessImpl::SetApplicationLocale(const std::string& locale) {
   locale_ = locale;
