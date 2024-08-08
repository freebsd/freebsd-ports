--- electron/shell/browser/browser_process_impl.cc.orig	2024-06-24 09:53:23 UTC
+++ electron/shell/browser/browser_process_impl.cc
@@ -334,7 +334,7 @@ electron::ResolveProxyHelper* BrowserProcessImpl::GetR
   return resolve_proxy_helper_.get();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void BrowserProcessImpl::SetLinuxStorageBackend(
     os_crypt::SelectedLinuxBackend selected_backend) {
   switch (selected_backend) {
@@ -358,7 +358,7 @@ void BrowserProcessImpl::SetLinuxStorageBackend(
       break;
   }
 }
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 void BrowserProcessImpl::SetApplicationLocale(const std::string& locale) {
   locale_ = locale;
