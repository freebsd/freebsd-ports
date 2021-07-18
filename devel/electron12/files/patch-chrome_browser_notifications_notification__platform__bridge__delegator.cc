--- chrome/browser/notifications/notification_platform_bridge_delegator.cc.orig	2021-04-14 01:08:40 UTC
+++ chrome/browser/notifications/notification_platform_bridge_delegator.cc
@@ -56,7 +56,7 @@ bool NativeNotificationsEnabled(Profile* profile) {
   return true;
 #elif defined(OS_WIN)
   return NotificationPlatformBridgeWin::NativeNotificationEnabled();
-#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#elif defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   if (profile) {
     // Prefs take precedence over flags.
     PrefService* prefs = profile->GetPrefs();
