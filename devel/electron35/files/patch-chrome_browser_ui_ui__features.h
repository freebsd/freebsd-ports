--- chrome/browser/ui/ui_features.h.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/ui/ui_features.h
@@ -52,7 +52,7 @@ bool IsExtensionMenuInRootAppMenu();
 BASE_DECLARE_FEATURE(kExtensionsMenuInAppMenu);
 bool IsExtensionMenuInRootAppMenu();
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kFewerUpdateConfirmations);
 #endif
 
@@ -229,7 +229,7 @@ BASE_DECLARE_FEATURE(kViewsJSAppModalDialog);
 BASE_DECLARE_FEATURE(kViewsJSAppModalDialog);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUsePortalAccentColor);
 #endif
 
