--- electron/shell/browser/browser_process_impl.h.orig	2024-06-24 09:53:23 UTC
+++ electron/shell/browser/browser_process_impl.h
@@ -23,7 +23,7 @@
 #include "services/network/public/cpp/shared_url_loader_factory.h"
 #include "shell/browser/net/system_network_context_manager.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "components/os_crypt/sync/key_storage_util_linux.h"
 #endif
 
@@ -61,7 +61,7 @@ class BrowserProcessImpl : public BrowserProcess {
   const std::string& GetSystemLocale() const;
   electron::ResolveProxyHelper* GetResolveProxyHelper();
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void SetLinuxStorageBackend(os_crypt::SelectedLinuxBackend selected_backend);
   [[nodiscard]] const std::string& linux_storage_backend() const {
     return selected_linux_storage_backend_;
@@ -147,7 +147,7 @@ class BrowserProcessImpl : public BrowserProcess {
   std::unique_ptr<PrefService> local_state_;
   std::string locale_;
   std::string system_locale_;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string selected_linux_storage_backend_;
 #endif
   embedder_support::OriginTrialsSettingsStorage origin_trials_settings_storage_;
