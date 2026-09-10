--- chrome/browser/safe_browsing/safe_browsing_pref_change_handler.cc.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/safe_browsing/safe_browsing_pref_change_handler.cc
@@ -19,7 +19,7 @@
 #include "content/public/browser/web_contents.h"
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_window/public/browser_window_features.h"
 #include "chrome/browser/ui/browser_window/public/browser_window_interface.h"
 #include "chrome/browser/ui/browser_window/public/profile_browser_collection.h"
@@ -74,7 +74,7 @@ void SafeBrowsingPrefChangeHandler::
     MaybeShowEnhancedProtectionSettingChangeNotification(
         content::WebContents* web_contents) {
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (!profile_ ||
       !base::FeatureList::IsEnabled(safe_browsing::kEsbAsASyncedSetting)) {
     return;
@@ -260,7 +260,7 @@ void SafeBrowsingPrefChangeHandler::
 }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 void SafeBrowsingPrefChangeHandler::SetToastControllerForTesting(
     ToastController* controller) {
   toast_controller_for_testing_ = controller;
