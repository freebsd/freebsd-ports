--- chrome/browser/notifications/notification_platform_bridge_delegator.cc.orig	2022-05-11 07:16:48 UTC
+++ chrome/browser/notifications/notification_platform_bridge_delegator.cc
@@ -57,7 +57,7 @@ bool SystemNotificationsEnabled(Profile* profile) {
 #elif defined(OS_WIN)
   return NotificationPlatformBridgeWin::SystemNotificationEnabled();
 #else
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   if (profile) {
     // Prefs take precedence over flags.
     PrefService* prefs = profile->GetPrefs();
