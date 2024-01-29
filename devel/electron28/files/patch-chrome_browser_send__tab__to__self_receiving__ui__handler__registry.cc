--- chrome/browser/send_tab_to_self/receiving_ui_handler_registry.cc.orig	2022-02-28 16:54:41 UTC
+++ chrome/browser/send_tab_to_self/receiving_ui_handler_registry.cc
@@ -16,7 +16,7 @@
 #include "components/send_tab_to_self/features.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/send_tab_to_self/desktop_notification_handler.h"
 #include "chrome/browser/ui/send_tab_to_self/send_tab_to_self_toolbar_icon_controller.h"
 #endif
@@ -48,7 +48,7 @@ SendTabToSelfToolbarIconController*
 ReceivingUiHandlerRegistry::GetToolbarButtonControllerForProfile(
     Profile* profile) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   for (const std::unique_ptr<ReceivingUiHandler>& handler :
        applicable_handlers_) {
     auto* button_controller =
