--- chrome/browser/safe_browsing/safe_browsing_service.cc.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/safe_browsing/safe_browsing_service.cc
@@ -83,7 +83,7 @@
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/browser_finder.h"
 #include "chrome/browser/ui/browser_window/public/browser_window_features.h"
 #include "chrome/browser/ui/toasts/api/toast_id.h"
@@ -554,7 +554,7 @@ void SafeBrowsingServiceImpl::EnhancedProtectionPrefCh
 void SafeBrowsingServiceImpl::EnhancedProtectionPrefChange(Profile* profile) {
   RefreshState();
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (!base::FeatureList::IsEnabled(safe_browsing::kEsbAsASyncedSetting) ||
       !profile) {
     return;
