--- chrome/browser/sync/device_info_sync_service_factory.cc.orig	2021-04-14 01:08:41 UTC
+++ chrome/browser/sync/device_info_sync_service_factory.cc
@@ -47,12 +47,12 @@ class DeviceInfoSyncClient : public syncer::DeviceInfo
 // in lacros-chrome once build flag switch of lacros-chrome is
 // complete.
 #if defined(OS_WIN) || defined(OS_MAC) || \
-    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS))
+    (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD)
     syncer::SyncPrefs prefs(profile_->GetPrefs());
     if (prefs.IsLocalSyncEnabled()) {
       return "local_device";
     }
-#endif  // defined(OS_WIN) || defined(OS_MAC) || (defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || (defined(OS_LINUX) || defined(OS_BSD) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS))
 
     return GetSigninScopedDeviceIdForProfile(profile_);
