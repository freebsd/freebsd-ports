--- chrome/browser/ui/ui_features.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/ui/ui_features.cc
@@ -74,7 +74,7 @@ bool IsExtensionMenuInRootAppMenu() {
   return base::FeatureList::IsEnabled(kExtensionsMenuInAppMenu);
 }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Enables the feature to remove the last confirmation dialog when relaunching
 // to update Chrome.
 BASE_FEATURE(kFewerUpdateConfirmations,
@@ -382,7 +382,7 @@ BASE_FEATURE(kViewsJSAppModalDialog,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kUsePortalAccentColor,
              "UsePortalAccentColor",
              base::FEATURE_ENABLED_BY_DEFAULT);
