--- chrome/browser/notifications/notification_display_service_impl.cc.orig	2021-07-15 19:13:33 UTC
+++ chrome/browser/notifications/notification_display_service_impl.cc
@@ -29,7 +29,7 @@
 #include "chrome/browser/extensions/api/notifications/extension_notification_handler.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 #include "chrome/browser/send_tab_to_self/desktop_notification_handler.h"
 #include "chrome/browser/sharing/sharing_notification_handler.h"
@@ -65,7 +65,7 @@ void NotificationDisplayServiceImpl::RegisterProfilePr
     user_prefs::PrefRegistrySyncable* registry) {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   registry->RegisterBooleanPref(prefs::kAllowNativeNotifications, true);
   registry->RegisterBooleanPref(prefs::kAllowSystemNotifications, true);
 #endif
@@ -81,7 +81,7 @@ NotificationDisplayServiceImpl::NotificationDisplaySer
     AddNotificationHandler(NotificationHandler::Type::WEB_PERSISTENT,
                            std::make_unique<PersistentNotificationHandler>());
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
     AddNotificationHandler(
         NotificationHandler::Type::SEND_TAB_TO_SELF,
