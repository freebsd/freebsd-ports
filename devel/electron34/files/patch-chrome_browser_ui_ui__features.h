--- chrome/browser/ui/ui_features.h.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/ui/ui_features.h
@@ -68,7 +68,7 @@ bool IsExtensionMenuInRootAppMenu();
 BASE_DECLARE_FEATURE(kExtensionsMenuInAppMenu);
 bool IsExtensionMenuInRootAppMenu();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kFewerUpdateConfirmations);
 #endif
 
@@ -277,7 +277,7 @@ BASE_DECLARE_FEATURE(kStopLoadingAnimationForHiddenWin
 
 BASE_DECLARE_FEATURE(kStopLoadingAnimationForHiddenWindow);
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUsePortalAccentColor);
 #endif
 
