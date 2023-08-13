--- electron/shell/browser/browser_process_impl.h.orig	2023-08-12 11:41:14 UTC
+++ electron/shell/browser/browser_process_impl.h
@@ -22,7 +22,7 @@
 #include "services/network/public/cpp/shared_url_loader_factory.h"
 #include "shell/browser/net/system_network_context_manager.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/os_crypt/sync/key_storage_util_linux.h"
 #endif
 
@@ -56,7 +56,7 @@ class BrowserProcessImpl : public BrowserProcess {
   void SetSystemLocale(const std::string& locale);
   const std::string& GetSystemLocale() const;
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetLinuxStorageBackend(os_crypt::SelectedLinuxBackend selected_backend);
   const std::string& GetLinuxStorageBackend() const;
 #endif
@@ -131,7 +131,7 @@ class BrowserProcessImpl : public BrowserProcess {
   std::unique_ptr<device::GeolocationManager> geolocation_manager_;
   std::string locale_;
   std::string system_locale_;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string selected_linux_storage_backend_;
 #endif
 
