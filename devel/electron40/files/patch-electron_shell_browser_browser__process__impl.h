--- electron/shell/browser/browser_process_impl.h.orig	2026-01-15 18:39:20 UTC
+++ electron/shell/browser/browser_process_impl.h
@@ -22,7 +22,7 @@
 #include "shell/browser/net/system_network_context_manager.h"
 #include "ui/base/unowned_user_data/unowned_user_data_host.h"
 
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
@@ -152,7 +152,7 @@ class BrowserProcessImpl : public BrowserProcess {
   std::unique_ptr<PrefService> local_state_;
   std::string locale_;
   std::string system_locale_;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   std::string selected_linux_storage_backend_;
 #endif
   embedder_support::OriginTrialsSettingsStorage origin_trials_settings_storage_;
