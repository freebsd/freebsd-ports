--- chrome/browser/ui/passwords/manage_passwords_ui_controller.cc.orig	2025-06-30 07:04:30 UTC
+++ chrome/browser/ui/passwords/manage_passwords_ui_controller.cc
@@ -104,7 +104,7 @@ using Logger = autofill::SavePasswordProgressLogger;
 
 using Logger = autofill::SavePasswordProgressLogger;
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Should be kept in sync with constant declared in
 // bubble_controllers/relaunch_chrome_bubble_controller.cc.
 constexpr int kMaxNumberOfTimesKeychainErrorBubbleIsShown = 3;
@@ -562,7 +562,7 @@ void ManagePasswordsUIController::OnKeychainError() {
 }
 
 void ManagePasswordsUIController::OnKeychainError() {
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   CHECK(!dialog_controller_);
   PrefService* prefs =
       Profile::FromBrowserContext(web_contents()->GetBrowserContext())
