--- electron/shell/browser/browser_process_impl.cc.orig	2024-02-28 05:54:17 UTC
+++ electron/shell/browser/browser_process_impl.cc
@@ -309,7 +309,7 @@ const std::string& BrowserProcessImpl::GetSystemLocale
   return system_locale_;
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void BrowserProcessImpl::SetLinuxStorageBackend(
     os_crypt::SelectedLinuxBackend selected_backend) {
   switch (selected_backend) {
@@ -333,7 +333,7 @@ void BrowserProcessImpl::SetLinuxStorageBackend(
       break;
   }
 }
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 void BrowserProcessImpl::SetApplicationLocale(const std::string& locale) {
   locale_ = locale;
