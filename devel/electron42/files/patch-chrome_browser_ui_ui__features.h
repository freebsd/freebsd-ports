--- chrome/browser/ui/ui_features.h.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/ui/ui_features.h
@@ -25,7 +25,7 @@ BASE_DECLARE_FEATURE(kCreateNewTabGroupAppMenuTopLevel
 
 BASE_DECLARE_FEATURE(kCreateNewTabGroupAppMenuTopLevel);
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kDseIntegrity);
 BASE_DECLARE_FEATURE(kFewerUpdateConfirmations);
 #endif
@@ -68,7 +68,7 @@ BASE_DECLARE_FEATURE_PARAM(int, kSeparateDefaultAndPin
 BASE_DECLARE_FEATURE_PARAM(int, kSeparateDefaultAndPinPromptMessageVersion);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // When enabled, user may see the session restore UI flow.
 BASE_DECLARE_FEATURE(kSessionRestoreInfobar);
 
@@ -257,7 +257,7 @@ BASE_DECLARE_FEATURE(kViewsJSAppModalDialog);
 BASE_DECLARE_FEATURE(kViewsJSAppModalDialog);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kUsePortalAccentColor);
 #endif
 
