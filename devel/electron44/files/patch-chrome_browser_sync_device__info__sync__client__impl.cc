--- chrome/browser/sync/device_info_sync_client_impl.cc.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/sync/device_info_sync_client_impl.cc
@@ -39,7 +39,7 @@ std::string DeviceInfoSyncClientImpl::GetSigninScopedD
 std::string DeviceInfoSyncClientImpl::GetSigninScopedDeviceId() const {
 // Since the local sync backend is currently only supported on Windows, Mac and
 // Linux don't even check the pref on other os-es.
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   syncer::SyncPrefs prefs(profile_->GetPrefs());
   if (prefs.IsLocalSyncEnabled()) {
     return "local_device";
