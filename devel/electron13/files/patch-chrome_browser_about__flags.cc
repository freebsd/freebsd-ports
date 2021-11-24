--- chrome/browser/about_flags.cc.orig	2021-07-15 19:13:32 UTC
+++ chrome/browser/about_flags.cc
@@ -937,7 +937,7 @@ const FeatureEntry::Choice kMemlogSamplingRateChoices[
      heap_profiling::kMemlogSamplingRate5MB},
 };
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 const FeatureEntry::FeatureParam kOmniboxDocumentProviderServerScoring[] = {
     {"DocumentUseServerScore", "true"},
@@ -1225,7 +1225,7 @@ const FeatureEntry::FeatureVariation
             nullptr,
         }};
 
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) ||
         // defined(OS_WIN)
 
 const FeatureEntry::FeatureVariation
@@ -3076,7 +3076,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kDeprecateLowUsageCodecs)},
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     {
         "enable-accelerated-video-decode",
         flag_descriptions::kAcceleratedVideoDecodeName,
@@ -3094,7 +3094,7 @@ const FeatureEntry kFeatureEntries[] = {
         kOsMac | kOsWin | kOsCrOS | kOsAndroid | kOsLinux,
         SINGLE_DISABLE_VALUE_TYPE(switches::kDisableAcceleratedVideoDecode),
     },
-#endif  // defined(OS_LINUX)
+#endif  // defined(OS_LINUX) || defined(OS_BSD)
     {
         "disable-accelerated-video-encode",
         flag_descriptions::kAcceleratedVideoEncodeName,
@@ -3439,7 +3439,7 @@ const FeatureEntry kFeatureEntries[] = {
     {"enable-login-detection", flag_descriptions::kEnableLoginDetectionName,
      flag_descriptions::kEnableLoginDetectionDescription, kOsAll,
      FEATURE_VALUE_TYPE(login_detection::kLoginDetection)},
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
     {"enable-save-data", flag_descriptions::kEnableSaveDataName,
      flag_descriptions::kEnableSaveDataDescription, kOsCrOS | kOsLinux,
      SINGLE_VALUE_TYPE(
@@ -3449,7 +3449,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableNavigationPredictorDescription,
      kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(blink::features::kNavigationPredictor)},
-#endif  // BUILDFLAG(IS_CHROMEOS_ASH) || OS_LINUX
+#endif  // BUILDFLAG(IS_CHROMEOS_ASH) || OS_LINUX || OS_BSD
     {"enable-preconnect-to-search",
      flag_descriptions::kEnablePreconnectToSearchName,
      flag_descriptions::kEnablePreconnectToSearchDescription, kOsAll,
@@ -4307,7 +4307,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsAll,
      FEATURE_VALUE_TYPE(omnibox::kOmniboxTrendingZeroPrefixSuggestionsOnNTP)},
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
@@ -4410,7 +4410,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_WITH_PARAMS_VALUE_TYPE(omnibox::kKeywordSpaceTriggering,
                                     kOmniboxKeywordSpaceTriggeringVariations,
                                     "OmniboxBundledExperimentV1")},
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) ||
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) ||
         // defined(OS_WIN)
 
     {"enable-speculative-service-worker-start-on-query-input",
@@ -4706,14 +4706,14 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chrome::android::kReaderModeInCCT)},
 #endif  // !defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"direct-manipulation-stylus",
      flag_descriptions::kDirectManipulationStylusName,
      flag_descriptions::kDirectManipulationStylusDescription,
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(features::kDirectManipulationStylus)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if !defined(OS_ANDROID)
@@ -5350,7 +5350,7 @@ const FeatureEntry kFeatureEntries[] = {
          chromeos::assistant::features::kAssistantBetterOnboarding)},
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"remote-copy-receiver", flag_descriptions::kRemoteCopyReceiverName,
      flag_descriptions::kRemoteCopyReceiverDescription, kOsDesktop,
@@ -5367,7 +5367,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kRemoteCopyProgressNotificationName,
      flag_descriptions::kRemoteCopyProgressNotificationDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(kRemoteCopyProgressNotification)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
     {"restrict-gamepad-access", flag_descriptions::kRestrictGamepadAccessName,
@@ -5398,7 +5398,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     kSharingDeviceExpirationVariations,
                                     "SharingDeviceExpiration")},
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
     {"sharing-hub-desktop-app-menu",
      flag_descriptions::kSharingHubDesktopAppMenuName,
      flag_descriptions::kSharingHubDesktopAppMenuDescription, kOsDesktop,
@@ -5407,7 +5407,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSharingHubDesktopOmniboxName,
      flag_descriptions::kSharingHubDesktopOmniboxDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(sharing_hub::kSharingHubDesktopOmnibox)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
 
 #if BUILDFLAG(IS_CHROMEOS_ASH)
     {"ash-enable-pip-rounded-corners",
@@ -5889,7 +5889,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kMouseSubframeNoImplicitCaptureDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kMouseSubframeNoImplicitCapture)},
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"global-media-controls", flag_descriptions::kGlobalMediaControlsName,
      flag_descriptions::kGlobalMediaControlsDescription,
@@ -5930,7 +5930,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kGlobalMediaControlsOverlayControlsDescription,
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(media::kGlobalMediaControlsOverlayControls)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
 #if BUILDFLAG(ENABLE_SPELLCHECK) && defined(OS_WIN)
@@ -6122,7 +6122,7 @@ const FeatureEntry kFeatureEntries[] = {
          kPasswordsAccountStorageVariations,
          "ButterForPasswords")},
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"passwords-account-storage-iph",
      flag_descriptions::kEnablePasswordsAccountStorageIPHName,
@@ -6130,7 +6130,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsWin | kOsMac | kOsLinux,
      FEATURE_VALUE_TYPE(
          feature_engagement::kIPHPasswordsAccountStorageFeature)},
-#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) ||
         // defined(OS_CHROMEOS)
 
     {"autofill-always-return-cloud-tokenized-card",
@@ -6731,7 +6731,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kEnableIncognitoShortcutOnDesktop)},
 #endif  // defined(OS_WIN)
 
-#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || \
+#if defined(OS_MAC) || defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"incognito-brand-consistency-for-desktop",
      flag_descriptions::kIncognitoBrandConsistencyForDesktopName,
@@ -6823,7 +6823,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(language::kDetailedLanguageSettings)},
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD)
     {"commander", flag_descriptions::kCommanderName,
      flag_descriptions::kCommanderDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kCommander)},
@@ -6860,7 +6860,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kEnhancedDeskAnimations)},
 #endif
 
-#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || \
+#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX) || defined(OS_BSD) || \
     defined(OS_CHROMEOS)
     {"enable-oop-print-drivers", flag_descriptions::kEnableOopPrintDriversName,
      flag_descriptions::kEnableOopPrintDriversDescription, kOsDesktop,
@@ -6879,14 +6879,14 @@ const FeatureEntry kFeatureEntries[] = {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC)
     {"enable-ephemeral-guest-profiles-on-desktop",
      flag_descriptions::kEnableEphemeralGuestProfilesOnDesktopName,
      flag_descriptions::kEnableEphemeralGuestProfilesOnDesktopDescription,
      kOsWin | kOsLinux | kOsMac,
      FEATURE_VALUE_TYPE(features::kEnableEphemeralGuestProfilesOnDesktop)},
-#endif  // defined(OS_WIN) || (defined(OS_LINUX) ||
+#endif  // defined(OS_WIN) || (defined(OS_LINUX) || defined(OS_BSD) ||
         // BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_MAC)
 
 #if defined(OS_ANDROID)
@@ -7162,7 +7162,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kVaapiAV1Decoder)},
 #endif  // defined(OS_CHROMEOS)
 
-#if defined(OS_WIN) || (defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
+#if defined(OS_WIN) || (defined(OS_LINUX) || defined(OS_BSD) || BUILDFLAG(IS_CHROMEOS_LACROS)) || defined(OS_BSD) || \
     defined(OS_MAC)
     {
         "ui-debug-tools",
@@ -7243,7 +7243,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(metrics::structured::kBluetoothSessionizedMetrics)},
 #endif
 
-#if defined(OS_LINUX) && defined(USE_OZONE)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && defined(USE_OZONE)
     {"use-ozone-platform", flag_descriptions::kUseOzonePlatformName,
      flag_descriptions::kUseOzonePlatformDescription, kOsLinux,
      FEATURE_VALUE_TYPE(features::kUseOzonePlatform)},
