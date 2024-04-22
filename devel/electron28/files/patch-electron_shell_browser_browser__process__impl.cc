--- electron/shell/browser/browser_process_impl.cc.orig	2024-04-09 23:57:48 UTC
+++ electron/shell/browser/browser_process_impl.cc
@@ -325,7 +325,7 @@ electron::ResolveProxyHelper* BrowserProcessImpl::GetR
   return resolve_proxy_helper_.get();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void BrowserProcessImpl::SetLinuxStorageBackend(
     os_crypt::SelectedLinuxBackend selected_backend) {
   switch (selected_backend) {
@@ -353,7 +353,7 @@ const std::string& BrowserProcessImpl::GetLinuxStorage
 const std::string& BrowserProcessImpl::GetLinuxStorageBackend() const {
   return selected_linux_storage_backend_;
 }
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 void BrowserProcessImpl::SetApplicationLocale(const std::string& locale) {
   locale_ = locale;
