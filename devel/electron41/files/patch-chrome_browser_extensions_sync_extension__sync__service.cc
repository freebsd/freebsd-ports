--- chrome/browser/extensions/sync/extension_sync_service.cc.orig	2026-03-13 16:54:03 UTC
+++ chrome/browser/extensions/sync/extension_sync_service.cc
@@ -634,7 +634,7 @@ void ExtensionSyncService::ApplySyncData(
     AccountExtensionTracker::Get(profile_)->OnExtensionSyncDataReceived(id);
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Chrome Apps are deprecated on WML, so we do not want to sync new apps
   // installed on other devices.
   if (extension_sync_data.is_app()) {
