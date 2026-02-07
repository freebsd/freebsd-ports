--- chrome/browser/ui/tabs/public/tab_features.h.orig	2025-10-21 20:19:54 UTC
+++ chrome/browser/ui/tabs/public/tab_features.h
@@ -118,7 +118,7 @@ class TabContextualizationController;
 }  // namespace lens
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 namespace wallet {
 class ChromeWalletablePassClient;
 }  // namespace wallet
@@ -451,7 +451,7 @@ class TabFeatures {
       bookmarkbar_preload_pipeline_manager_;
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   std::unique_ptr<wallet::ChromeWalletablePassClient> walletable_pass_client_;
 #endif
   // Must be the last member.
