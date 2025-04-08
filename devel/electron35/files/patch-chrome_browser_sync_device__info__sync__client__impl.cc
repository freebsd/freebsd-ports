--- chrome/browser/sync/device_info_sync_client_impl.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/sync/device_info_sync_client_impl.cc
@@ -43,7 +43,7 @@ std::string DeviceInfoSyncClientImpl::GetSigninScopedD
 // included in lacros-chrome once build flag switch of lacros-chrome is
 // complete.
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || \
-    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || BUILDFLAG(IS_BSD))
   syncer::SyncPrefs prefs(profile_->GetPrefs());
   if (prefs.IsLocalSyncEnabled()) {
     return "local_device";
