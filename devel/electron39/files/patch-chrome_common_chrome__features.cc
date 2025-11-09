--- chrome/common/chrome_features.cc.orig	2025-10-21 20:19:54 UTC
+++ chrome/common/chrome_features.cc
@@ -86,7 +86,7 @@ BASE_FEATURE(kUseAdHocSigningForWebAppShims, base::FEA
 #endif  // BUILDFLAG(IS_MAC)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables or disables the Autofill survey triggered by opening a prompt to
 // save address info.
 BASE_FEATURE(kAutofillAddressSurvey, base::FEATURE_DISABLED_BY_DEFAULT);
@@ -98,7 +98,7 @@ BASE_FEATURE(kAutofillPasswordSurvey, base::FEATURE_DI
 BASE_FEATURE(kAutofillPasswordSurvey, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 // Enables the Restart background mode optimization. When all Chrome UI is
 // closed and it goes in the background, allows to restart the browser to
 // discard memory.
@@ -214,7 +214,7 @@ BASE_FEATURE(kDesktopPWAsRunOnOsLogin,
 // Enables or disables Desktop PWAs to be auto-started on OS login.
 BASE_FEATURE(kDesktopPWAsRunOnOsLogin,
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT
 #else
              base::FEATURE_DISABLED_BY_DEFAULT
@@ -248,7 +248,7 @@ BASE_FEATURE(kEnableFullscreenToAnyScreenAndroid,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // Controls whether Chrome Apps are supported. See https://crbug.com/1221251.
 // If the feature is disabled, Chrome Apps continue to work. If enabled, Chrome
 // Apps will not launch and will be marked in the UI as deprecated.
@@ -627,7 +627,7 @@ BASE_FEATURE(kGlicGuestContentsVisibilityState,
 // Killswitch that controls whether the guest WebContents visibility state is
 // set to hidden when the Glic panel is warming.
 BASE_FEATURE(kGlicGuestContentsVisibilityState,
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
              base::FEATURE_ENABLED_BY_DEFAULT);
 #else
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -1088,7 +1088,7 @@ BASE_FEATURE(kKAnonymityServiceStorage, base::FEATURE_
 // public keys.
 BASE_FEATURE(kKAnonymityServiceStorage, base::FEATURE_ENABLED_BY_DEFAULT);
 
-#if BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && !BUILDFLAG(IS_CHROMEOS)
 BASE_FEATURE(kLinuxLowMemoryMonitor, base::FEATURE_DISABLED_BY_DEFAULT);
 // Values taken from the low-memory-monitor documentation and also apply to the
 // portal API:
@@ -1099,7 +1099,7 @@ constexpr base::FeatureParam<int> kLinuxLowMemoryMonit
     &kLinuxLowMemoryMonitor, "critical_level", 255};
 #endif  // BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kListWebAppsSwitch, base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
