--- chrome/browser/send_tab_to_self/receiving_ui_handler_registry.cc.orig	2021-01-07 00:36:24 UTC
+++ chrome/browser/send_tab_to_self/receiving_ui_handler_registry.cc
@@ -11,7 +11,7 @@
 #include "chrome/browser/profiles/profile.h"
 #include "chrome/browser/send_tab_to_self/receiving_ui_handler.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 #include "chrome/browser/send_tab_to_self/desktop_notification_handler.h"
 #endif
@@ -33,7 +33,7 @@ ReceivingUiHandlerRegistry* ReceivingUiHandlerRegistry
 // Instantiates all the handlers relevant to this platform.
 void ReceivingUiHandlerRegistry::InstantiatePlatformSpecificHandlers(
     Profile* profile) {
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
   applicable_handlers_.push_back(
       std::make_unique<send_tab_to_self::DesktopNotificationHandler>(profile));
