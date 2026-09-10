--- electron/shell/browser/browser_process_impl.cc.orig	2026-08-31 00:54:19 UTC
+++ electron/shell/browser/browser_process_impl.cc
@@ -51,7 +51,7 @@
 #include "chrome/browser/printing/print_job_manager.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_features.h"
 #include "components/os_crypt/async/browser/freedesktop_secret_key_provider.h"
 #include "components/os_crypt/async/browser/secret_portal_key_provider.h"
@@ -150,7 +150,7 @@ void BrowserProcessImpl::PostEarlyInitialization() {
   OSCrypt::RegisterLocalPrefs(pref_registry.get());
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   os_crypt_async::SecretPortalKeyProvider::RegisterLocalPrefs(
       pref_registry.get());
 #endif
@@ -407,7 +407,7 @@ electron::ResolveProxyHelper* BrowserProcessImpl::GetR
   return resolve_proxy_helper_.get();
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void BrowserProcessImpl::SetLinuxStorageBackend(
     os_crypt::SelectedLinuxBackend selected_backend) {
   switch (selected_backend) {
@@ -430,7 +430,7 @@ void BrowserProcessImpl::SetLinuxStorageBackend(
       NOTREACHED();
   }
 }
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 void BrowserProcessImpl::SetApplicationLocale(const std::string& locale) {
   locale_ = locale;
@@ -482,7 +482,7 @@ void BrowserProcessImpl::CreateOSCryptAsync() {
       std::make_unique<os_crypt_async::DPAPIKeyProvider>(local_state()));
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   base::CommandLine* cmd_line = base::CommandLine::ForCurrentProcess();
   const auto password_store =
       cmd_line->GetSwitchValueASCII(password_manager::kPasswordStore);
@@ -510,7 +510,7 @@ void BrowserProcessImpl::CreateOSCryptAsync() {
       std::make_unique<os_crypt_async::FreedesktopSecretKeyProvider>(
           password_store, electron::GetApplicationName(), freedesktop_config,
           nullptr));
-#endif  // BUILDFLAG(IS_LINUX)
+#endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 
 #if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC)
   // On other POSIX systems, this is the only key provider. On Linux, it is used
