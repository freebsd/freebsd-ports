--- chrome/browser/safe_browsing/safe_browsing_pref_change_handler.h.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/safe_browsing/safe_browsing_pref_change_handler.h
@@ -21,7 +21,7 @@
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/toasts/toast_controller.h"
 #endif
 
@@ -72,7 +72,7 @@ class SafeBrowsingPrefChangeHandler {
   }
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   void SetToastControllerForTesting(ToastController* controller);
 #endif
 
@@ -85,7 +85,7 @@ class SafeBrowsingPrefChangeHandler {
   raw_ptr<Profile> profile_;
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   raw_ptr<ToastController> toast_controller_for_testing_ = nullptr;
 #endif
 
