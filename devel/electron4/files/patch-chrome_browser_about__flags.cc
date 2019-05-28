--- chrome/browser/about_flags.cc.orig	2019-03-15 06:37:01 UTC
+++ chrome/browser/about_flags.cc
@@ -2436,7 +2436,7 @@ const FeatureEntry kFeatureEntries[] = {
     {"force-text-direction", flag_descriptions::kForceTextDirectionName,
      flag_descriptions::kForceTextDirectionDescription, kOsAll,
      MULTI_VALUE_TYPE(kForceTextDirectionChoices)},
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-input-ime-api", flag_descriptions::kEnableInputImeApiName,
      flag_descriptions::kEnableInputImeApiDescription, kOsWin | kOsLinux,
      ENABLE_DISABLE_VALUE_TYPE(switches::kEnableInputImeAPI,
@@ -2446,7 +2446,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kWarnBeforeQuittingFlagDescription, kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(features::kWarnBeforeQuitting)},
 #endif  // OS_CHROMEOS
-#endif  // OS_WIN || OS_LINUX
+#endif  // OS_WIN || OS_LINUX || OS_BSD
     {"enable-origin-trials", flag_descriptions::kOriginTrialsName,
      flag_descriptions::kOriginTrialsDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kOriginTrials)},
@@ -3059,7 +3059,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kLeftToRightUrlsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kLeftToRightUrls)},
 
-#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#if defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
     {"omnibox-new-answer-layout",
      flag_descriptions::kOmniboxNewAnswerLayoutName,
      flag_descriptions::kOmniboxNewAnswerLayoutDescription, kOsDesktop,
@@ -3081,7 +3081,7 @@ const FeatureEntry kFeatureEntries[] = {
     {"enable-new-app-menu-icon", flag_descriptions::kEnableNewAppMenuIconName,
      flag_descriptions::kEnableNewAppMenuIconDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kAnimatedAppMenuIcon)},
-#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN)
+#endif  // defined(OS_LINUX) || defined(OS_MACOSX) || defined(OS_WIN) || defined(OS_BSD)
 
 #if defined(OS_ANDROID)
     {"enable-custom-feedback-ui",
@@ -3415,13 +3415,13 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kClickToOpenPDFDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kClickToOpenPDFPlaceholder)},
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"direct-manipulation-stylus",
      flag_descriptions::kDirectManipulationStylusName,
      flag_descriptions::kDirectManipulationStylusDescription,
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(features::kDirectManipulationStylus)},
-#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if !defined(OS_ANDROID)
     {"remove-deprecared-gaia-signin-endpoint",
@@ -3913,7 +3913,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kOverviewSwipeToClose)},
 #endif  // OS_CHROMEOS
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
     {"ntp-backgrounds", flag_descriptions::kNtpBackgroundsName,
      flag_descriptions::kNtpBackgroundsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kNtpBackgrounds)},
@@ -3929,7 +3929,7 @@ const FeatureEntry kFeatureEntries[] = {
     {"ntp-ui-md", flag_descriptions::kNtpUIMdName,
      flag_descriptions::kNtpUIMdDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kNtpUIMd)},
-#endif  // OS_WIN || OS_MACOSX || OS_LINUX
+#endif  // OS_WIN || OS_MACOSX || OS_LINUX || OS_BSD
 
 #if defined(OS_ANDROID)
     {"enable-display-cutout-api", flag_descriptions::kDisplayCutoutAPIName,
