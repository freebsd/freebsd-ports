--- electron/shell/browser/browser_process_impl.cc.orig	2024-10-22 02:29:46 UTC
+++ electron/shell/browser/browser_process_impl.cc
@@ -338,7 +338,7 @@ electron::ResolveProxyHelper* BrowserProcessImpl::GetR
   return resolve_proxy_helper_.get();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void BrowserProcessImpl::SetLinuxStorageBackend(
     os_crypt::SelectedLinuxBackend selected_backend) {
   switch (selected_backend) {
@@ -361,7 +361,7 @@ void BrowserProcessImpl::SetLinuxStorageBackend(
       NOTREACHED();
   }
 }
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 void BrowserProcessImpl::SetApplicationLocale(const std::string& locale) {
   locale_ = locale;
