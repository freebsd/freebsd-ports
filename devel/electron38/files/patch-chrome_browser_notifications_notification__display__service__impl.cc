--- chrome/browser/notifications/notification_display_service_impl.cc.orig	2025-04-22 20:15:27 UTC
+++ chrome/browser/notifications/notification_display_service_impl.cc
@@ -31,7 +31,7 @@
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/send_tab_to_self/desktop_notification_handler.h"
 #include "chrome/browser/sharing/sharing_notification_handler.h"
 #endif
@@ -60,7 +60,7 @@ void NotificationDisplayServiceImpl::RegisterProfilePr
 // static
 void NotificationDisplayServiceImpl::RegisterProfilePrefs(
     user_prefs::PrefRegistrySyncable* registry) {
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   registry->RegisterBooleanPref(prefs::kAllowSystemNotifications, true);
 #endif
 }
@@ -76,7 +76,7 @@ NotificationDisplayServiceImpl::NotificationDisplaySer
                            std::make_unique<PersistentNotificationHandler>());
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     AddNotificationHandler(
         NotificationHandler::Type::SEND_TAB_TO_SELF,
         std::make_unique<send_tab_to_self::DesktopNotificationHandler>(
@@ -84,7 +84,7 @@ NotificationDisplayServiceImpl::NotificationDisplaySer
 #endif
 
 #if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-     BUILDFLAG(IS_WIN)) &&                                                 \
+     BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)) &&                            \
     BUILDFLAG(SAFE_BROWSING_AVAILABLE)
     AddNotificationHandler(
         NotificationHandler::Type::TAILORED_SECURITY,
