--- chrome/browser/safe_browsing/safe_browsing_pref_change_handler.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/safe_browsing/safe_browsing_pref_change_handler.cc
@@ -19,7 +19,7 @@
 #include "content/public/browser/web_contents.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/browser_window/public/browser_window_features.h"
 #include "chrome/browser/ui/toasts/api/toast_id.h"
@@ -73,7 +73,7 @@ void SafeBrowsingPrefChangeHandler::
 void SafeBrowsingPrefChangeHandler::
     MaybeShowEnhancedProtectionSettingChangeNotification() {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (!profile_ ||
       !base::FeatureList::IsEnabled(safe_browsing::kEsbAsASyncedSetting)) {
     return;
@@ -243,7 +243,7 @@ void SafeBrowsingPrefChangeHandler::
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 void SafeBrowsingPrefChangeHandler::SetToastControllerForTesting(
     ToastController* controller) {
   toast_controller_for_testing_ = controller;
