--- chrome/browser/browser_process_impl.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/browser_process_impl.cc
@@ -259,7 +259,7 @@
 #include "components/enterprise/browser/controller/chrome_browser_cloud_management_controller.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/browser_features.h"
 #include "components/os_crypt/async/browser/fallback_linux_key_provider.h"
 #include "components/os_crypt/async/browser/freedesktop_secret_key_provider.h"
@@ -1135,7 +1135,7 @@ void BrowserProcessImpl::RegisterPrefs(PrefRegistrySim
                                 GoogleUpdateSettings::GetCollectStatsConsent());
   registry->RegisterBooleanPref(prefs::kDevToolsRemoteDebuggingAllowed, true);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   os_crypt_async::SecretPortalKeyProvider::RegisterLocalPrefs(registry);
 #endif
 }
@@ -1405,7 +1405,7 @@ void BrowserProcessImpl::PreMainMessageLoopRun() {
           local_state())));
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kDbusSecretPortal)) {
     providers.emplace_back(
         /*precedence=*/10u,
@@ -1672,7 +1672,7 @@ void BrowserProcessImpl::Unpin() {
 // Mac is currently not supported.
 // TODO(crbug.com/40118868): Revisit once build flag switch of lacros-chrome is
 // complete.
-#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+#if BUILDFLAG(IS_WIN) || (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || BUILDFLAG(IS_BSD)
 
 bool BrowserProcessImpl::IsRunningInBackground() const {
   // Check if browser is in the background.
