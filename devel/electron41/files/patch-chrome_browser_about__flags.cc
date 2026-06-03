--- chrome/browser/about_flags.cc.orig	2026-03-30 20:35:34 UTC
+++ chrome/browser/about_flags.cc
@@ -331,13 +331,13 @@
 #include "components/stylus_handwriting/win/features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "base/allocator/buildflags.h"
 #include "ui/ozone/public/ozone_switches.h"
 #endif
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/contextual_cueing/contextual_cueing_features.h"  // nogncheck
 #include "chrome/browser/enterprise/data_protection/data_protection_features.h"
 #include "chrome/browser/enterprise/profile_management/profile_management_features.h"
@@ -354,7 +354,7 @@
 #include "components/enterprise/platform_auth/platform_auth_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/enterprise/reporting/reporting_features.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
@@ -787,6 +787,23 @@ const FeatureEntry::FeatureVariation
          "identity request to Android OS",
          kWebIdentityDigitalIdentityCredentialHighRiskDialogParam, nullptr}};
 
+#if BUILDFLAG(IS_BSD)
+const FeatureEntry::FeatureParam kAudioBackendPulseAudio[] = {
+        { "audio-backend", "pulseaudio" }};
+const FeatureEntry::FeatureParam kAudioBackendSndio[] = {
+        { "audio-backend", "sndio" }};
+const FeatureEntry::FeatureParam kAudioBackendAlsa[] = {
+        { "audio-backend", "alsa" }};
+const FeatureEntry::FeatureVariation
+    kAudioBackendVariations[] = {
+        {"using PulseAudio by default if available",
+         kAudioBackendPulseAudio, nullptr},
+        {"using sndio by default if available",
+         kAudioBackendSndio, nullptr},
+        {"using ALSA by default if available",
+         kAudioBackendAlsa, nullptr}};
+#endif
+
 const FeatureEntry::FeatureParam kMBIModeLegacy[] = {{"mode", "legacy"}};
 const FeatureEntry::FeatureParam kMBIModeEnabledPerRenderProcessHost[] = {
     {"mode", "per_render_process_host"}};
@@ -1203,7 +1220,7 @@ const FeatureEntry::FeatureVariation
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 // A limited number of combinations of the rich autocompletion params.
 const FeatureEntry::FeatureParam kOmniboxRichAutocompletionAggressive1[] = {
@@ -3403,7 +3420,7 @@ const FeatureEntry::FeatureVariation kAndroidThemeReso
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOn[] =
     {{"link_capturing_state", "on_by_default"}};
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOff[] =
@@ -3429,7 +3446,7 @@ const flags_ui::FeatureEntry::FeatureVariation
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) ||
         // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const FeatureEntry::Choice kReplaceSyncPromosWithSignInPromosChoices[] = {
     {"Default", "", ""},
     {"Disabled", switches::kDisableFeatures,
@@ -3631,7 +3648,7 @@ const FeatureEntry::FeatureVariation kSensitiveContent
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kContextualCueingEnabledNoEngagementCap[] = {
     {"BackoffTime", "0h"},
     {"BackoffMultiplierBase", "0.0"},
@@ -4370,7 +4387,7 @@ const FeatureEntry::FeatureVariation
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kNtpCustomizeChromeAutoOpenOnEveryNTP[] = {
     {"max_customize_chrome_auto_shown_count", "5"},
     {"max_customize_chrome_auto_shown_session_count", "5"}};
@@ -4471,7 +4488,7 @@ const FeatureEntry::FeatureVariation kSeamlessSigninVa
      kSeamlessSigninCompactSignin, nullptr}};
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kProfilePickerTextVariation1[] = {
     {"profile-picker-variation", "keep-work-and-life-separate"}};
 const FeatureEntry::FeatureParam kProfilePickerTextVariation2[] = {
@@ -5443,7 +5460,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableIsolatedWebAppDevModeName,
      flag_descriptions::kEnableIsolatedWebAppDevModeDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kIsolatedWebAppDevMode)},
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-iwa-key-distribution-component",
      flag_descriptions::kEnableIwaKeyDistributionComponentName,
      flag_descriptions::kEnableIwaKeyDistributionComponentDescription,
@@ -5634,7 +5651,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kUseSCContentSharingPicker)},
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"pulseaudio-loopback-for-cast",
      flag_descriptions::kPulseaudioLoopbackForCastName,
      flag_descriptions::kPulseaudioLoopbackForCastDescription, kOsLinux,
@@ -5649,6 +5666,16 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kWaylandSessionManagementName,
      flag_descriptions::kWaylandSessionManagementDescription, kOsLinux,
      FEATURE_VALUE_TYPE(features::kWaylandSessionManagement)},
+
+#if BUILDFLAG(IS_BSD)
+    {"audio-backend",
+     flag_descriptions::kAudioBackendName,
+     flag_descriptions::kAudioBackendDescription, kOsLinux,
+     FEATURE_WITH_PARAMS_VALUE_TYPE(
+         media::kAudioBackend,
+         kAudioBackendVariations,
+         "AudioBackend")},
+#endif
 #endif  // BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(ENABLE_VR)
@@ -6144,7 +6171,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kFillOnAccountSelectDescription, kOsAll,
      FEATURE_VALUE_TYPE(password_manager::features::kFillOnAccountSelect)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"first-run-desktop-refresh",
      flag_descriptions::kFirstRunDesktopRefreshName,
      flag_descriptions::kFirstRunDesktopRefreshDescription,
@@ -6480,7 +6507,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "MlUrlScoring")},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"contextual-search-box-uses-contextual-search-provider",
      flag_descriptions::kContextualSearchBoxUsesContextualSearchProviderName,
      flag_descriptions::
@@ -6888,7 +6915,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     kNumSrpZpsRelatedSearches,
                                     "PowerTools")},
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"history-embeddings", flag_descriptions::kHistoryEmbeddingsName,
      flag_descriptions::kHistoryEmbeddingsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(history_embeddings::kHistoryEmbeddings)},
@@ -7073,7 +7100,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "NtpRealboxNext")},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"ntp-customize-chrome-auto-open",
      flag_descriptions::kNtpCustomizeChromeAutoOpenName,
      flag_descriptions::kNtpCustomizeChromeAutoOpenDescription, kOsDesktop,
@@ -7319,7 +7346,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(ENABLE_PRINTING)
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"cups-ipp-printing-backend",
      flag_descriptions::kCupsIppPrintingBackendName,
      flag_descriptions::kCupsIppPrintingBackendDescription, kOsDesktop,
@@ -8172,7 +8199,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kGesturePropertiesDBusService)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-network-service-sandbox",
      flag_descriptions::kEnableNetworkServiceSandboxName,
      flag_descriptions::kEnableNetworkServiceSandboxDescription,
@@ -8693,7 +8720,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kGlobalVaapiLockDescription, kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(media::kGlobalVaapiLock)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {
         "ui-debug-tools",
         flag_descriptions::kUIDebugToolsName,
@@ -9147,7 +9174,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"auto-picture-in-picture-for-video-playback",
      flag_descriptions::kAutoPictureInPictureForVideoPlaybackName,
      flag_descriptions::kAutoPictureInPictureForVideoPlaybackDescription,
@@ -9328,7 +9355,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kReduceTransferSizeUpdatedIPCDescription, kOsAll,
      FEATURE_VALUE_TYPE(network::features::kReduceTransferSizeUpdatedIPC)},
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"reduce-user-agent-data-linux-platform-version",
      flag_descriptions::kReduceUserAgentDataLinuxPlatformVersionName,
      flag_descriptions::kReduceUserAgentDataLinuxPlatformVersionDescription,
@@ -9827,7 +9854,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kRcapsDynamicProfileCountryDescription, kOsAll,
      FEATURE_VALUE_TYPE(switches::kDynamicProfileCountry)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"enable-generic-oidc-auth-profile-management",
      flag_descriptions::kEnableGenericOidcAuthProfileManagementName,
      flag_descriptions::kEnableGenericOidcAuthProfileManagementDescription,
@@ -9842,7 +9869,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-user-navigation-capturing-pwa",
      flag_descriptions::kPwaNavigationCapturingName,
      flag_descriptions::kPwaNavigationCapturingDescription,
@@ -10245,7 +10272,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kResponsiveIframesDescription, kOsAll,
      FEATURE_VALUE_TYPE(blink::features::kResponsiveIframes)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"replace-sync-promos-with-sign-in-promos-desktop",
      flag_descriptions::kReplaceSyncPromosWithSignInPromosName,
      flag_descriptions::kReplaceSyncPromosWithSignInPromosDescription,
@@ -10601,7 +10628,7 @@ const FeatureEntry kFeatureEntries[] = {
          segmentation_platform::features::kSegmentationSurveyPage)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later",
      flag_descriptions::kAutofillEnableBuyNowPayLaterName,
      flag_descriptions::kAutofillEnableBuyNowPayLaterDescription,
@@ -10680,7 +10707,7 @@ const FeatureEntry kFeatureEntries[] = {
          password_manager::features::kPasswordFormClientsideClassifier)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"contextual-cueing", flag_descriptions::kContextualCueingName,
      flag_descriptions::kContextualCueingDescription, kOsDesktop,
      FEATURE_WITH_PARAMS_VALUE_TYPE(contextual_cueing::kContextualCueing,
@@ -11071,7 +11098,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ui::kUseNewEtc1Encoder)},
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"automatic-usb-detach", flag_descriptions::kAutomaticUsbDetachName,
      flag_descriptions::kAutomaticUsbDetachDescription, kOsAndroid | kOsLinux,
      FEATURE_VALUE_TYPE(features::kAutomaticUsbDetach)},
@@ -11102,7 +11129,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction",
      flag_descriptions::kAutofillEnableAmountExtractionName,
      flag_descriptions::kAutofillEnableAmountExtractionDescription,
@@ -11254,7 +11281,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          feature_engagement::kIPHAutofillCreditCardBenefitFeature)},
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"chrome-web-store-navigation-throttle",
      flag_descriptions::kChromeWebStoreNavigationThrottleName,
      flag_descriptions::kChromeWebStoreNavigationThrottleDescription,
@@ -11300,7 +11327,7 @@ const FeatureEntry kFeatureEntries[] = {
          supervised_user::kSupervisedUserUseUrlFilteringService)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction-testing",
      flag_descriptions::kAutofillEnableAmountExtractionTestingName,
      flag_descriptions::kAutofillEnableAmountExtractionTestingDescription,
@@ -11315,7 +11342,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableWebAppPredictableAppUpdatingDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kWebAppPredictableAppUpdating)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"root-scrollbar-follows-browser-theme",
      flag_descriptions::kRootScrollbarFollowsTheme,
      flag_descriptions::kRootScrollbarFollowsThemeDescription,
@@ -11569,7 +11596,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"tab-group-home", tabs::flag_descriptions::kTabGroupHomeName,
      tabs::flag_descriptions::kTabGroupHomeDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(tabs::kTabGroupHome)},
@@ -11639,7 +11666,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-site-search-allow-user-override-policy",
      flag_descriptions::kEnableSiteSearchAllowUserOverridePolicyName,
      flag_descriptions::kEnableSiteSearchAllowUserOverridePolicyDescription,
@@ -11720,7 +11747,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later-for-klarna",
      flag_descriptions::kAutofillEnableBuyNowPayLaterForKlarnaName,
      flag_descriptions::kAutofillEnableBuyNowPayLaterForKlarnaDescription,
@@ -11784,7 +11811,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(ENABLE_DICE_SUPPORT)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later-for-externally-linked",
      flag_descriptions::kAutofillEnableBuyNowPayLaterForExternallyLinkedName,
      flag_descriptions::
@@ -12093,7 +12120,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // !BUILDFLAG(IS_ANDROID),
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-ntp-enterprise-shortcuts",
      flag_descriptions::kEnableNtpEnterpriseShortcutsName,
      flag_descriptions::kEnableNtpEnterpriseShortcutsDescription,
@@ -12204,7 +12231,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"contextual-suggestion-ui-improvements",
      flag_descriptions::kContextualSuggestionsUiImprovementsName,
      flag_descriptions::kContextualSuggestionsUiImprovementsDescription,
@@ -12224,7 +12251,7 @@ const FeatureEntry kFeatureEntries[] = {
          autofill::features::kAutofillPreferBuyNowPayLaterBlocklists)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"autofill-enable-ai-based-amount-extraction",
      flag_descriptions::kAutofillEnableAiBasedAmountExtractionName,
      flag_descriptions::kAutofillEnableAiBasedAmountExtractionDescription,
@@ -12306,7 +12333,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kCryptographyComplianceCnsa)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"lens-reinvocation-affordance",
      flag_descriptions::kLensSearchReinvocationAffordanceName,
      flag_descriptions::kLensSearchReinvocationAffordanceDescription,
@@ -12364,7 +12391,7 @@ const FeatureEntry kFeatureEntries[] = {
      STRING_VALUE_TYPE(variations::switches::kVariationsSeedCorpus, "")},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"passkey-unlock-manager", flag_descriptions::kPasskeyUnlockManagerName,
      flag_descriptions::kPasskeyUnlockManagerDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(device::kPasskeyUnlockManager)},
@@ -12405,7 +12432,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kUserValueDefaultBrowserStrings)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-read-aloud-ts-text-segmentation",
      flag_descriptions::kReadAnythingReadAloudTsTextSegmentationName,
      flag_descriptions::kReadAnythingReadAloudTsTextSegmentationDescription,
@@ -12417,7 +12444,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kHandleMdmErrorsForDasherAccountsDescription, kOsAll,
      FEATURE_VALUE_TYPE(switches::kHandleMdmErrorsForDasherAccounts)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"profile-creation-decline-signin-cta-experiment",
      flag_descriptions::kProfileCreationDeclineSigninCTAExperimentName,
      flag_descriptions::kProfileCreationDeclineSigninCTAExperimentDescription,
@@ -12425,7 +12452,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(switches::kProfileCreationDeclineSigninCTAExperiment)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"profile-creation-friction-reduction-experiment-prefill-name-requirement",
      flag_descriptions::
          kProfileCreationFrictionReductionExperimentPrefillNameRequirementName,
@@ -12437,7 +12464,7 @@ const FeatureEntry kFeatureEntries[] = {
              kProfileCreationFrictionReductionExperimentPrefillNameRequirement)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"profile-creation-friction-reduction-experiment-remove-signin-step",
      flag_descriptions::
          kProfileCreationFrictionReductionExperimentRemoveSigninStepName,
@@ -12449,7 +12476,7 @@ const FeatureEntry kFeatureEntries[] = {
              kProfileCreationFrictionReductionExperimentRemoveSigninStep)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"profile-creation-friction-reduction-experiment-skip-customize-profile",
      flag_descriptions::
          kProfileCreationFrictionReductionExperimentSkipCustomizeProfileName,
@@ -12461,7 +12488,7 @@ const FeatureEntry kFeatureEntries[] = {
              kProfileCreationFrictionReductionExperimentSkipCustomizeProfile)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"show-profile-picker-to-all-users-experiment",
      flag_descriptions::kShowProfilePickerToAllUsersExperimentName,
      flag_descriptions::kShowProfilePickerToAllUsersExperimentDescription,
@@ -12469,7 +12496,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(switches::kShowProfilePickerToAllUsersExperiment)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"open-all-profiles-from-profile-picker-experiment",
      flag_descriptions::kOpenAllProfilesFromProfilePickerExperimentName,
      flag_descriptions::kOpenAllProfilesFromProfilePickerExperimentDescription,
@@ -12512,7 +12539,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "AndroidDesktopZoomScaling")},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"profile-picker-text-variations",
      flag_descriptions::kProfilePickerTextVariationsName,
      flag_descriptions::kProfilePickerTextVariationsDescription,
@@ -12523,7 +12550,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"lens-overlay-optimization-filter",
      flag_descriptions::kLensOverlayOptimizationFilterName,
      flag_descriptions::kLensOverlayOptimizationFilterDescription, kOsDesktop,
@@ -12542,7 +12569,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(network::features::kConnectionAllowlists)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-with-readability-enabled",
      flag_descriptions::kReadAnythingWithReadabilityName,
      flag_descriptions::kReadAnythingWithReadabilityDescription, kOsDesktop,
@@ -12550,7 +12577,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-omnibox-chip",
      flag_descriptions::kReadAnythingOmniboxChipName,
      flag_descriptions::kReadAnythingOmniboxChipDescription, kOsDesktop,
@@ -12579,7 +12606,7 @@ const FeatureEntry kFeatureEntries[] = {
          autofill::features::kAutofillDisableBnplCountryCheckForTesting)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"infobar-prioritization", flag_descriptions::kInfobarPrioritizationName,
      flag_descriptions::kInfobarPrioritizationDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(infobars::features::kInfobarPrioritization)},
@@ -12597,7 +12624,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-immersive-reading-mode",
      flag_descriptions::kReadAnythingImmersiveReadingModeName,
      flag_descriptions::kReadAnythingImmersiveReadingModeDescription,
@@ -12610,7 +12637,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"lens-overlay-non-blocking-privacy-notice",
      flag_descriptions::kLensOverlayNonBlockingPrivacyNoticeName,
      flag_descriptions::kLensOverlayNonBlockingPrivacyNoticeDescription,
@@ -12683,7 +12710,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-your-saved-info-settings-page",
      flag_descriptions::kYourSavedInfoSettingsPageName,
      flag_descriptions::kYourSavedInfoSettingsPageDescription, kOsDesktop,
@@ -12780,14 +12807,14 @@ const FeatureEntry kFeatureEntries[] = {
          autofill::features::
              kAutofillAiBasedAmountExtractionIgnoreSeenTermsForTesting)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"updater-ui", flag_descriptions::kUpdaterUIName,
      flag_descriptions::kUpdaterUIDescription, kOsLinux | kOsMac | kOsWin,
      FEATURE_VALUE_TYPE(features::kUpdaterUI)},
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"read-anything-line-focus", flag_descriptions::kReadAnythingLineFocusName,
      flag_descriptions::kReadAnythingLineFocusDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kReadAnythingLineFocus)},
@@ -12811,7 +12838,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(payments::android::kDeduplicateNativePaymentApps)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"password-upload-ui-update",
      flag_descriptions::kPasswordUploadUiUpdateName,
      flag_descriptions::kPasswordUploadUiUpdateDescription,
@@ -12840,7 +12867,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chrome::android::kAlwaysDrawCompositedToolbarHairline)},
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"saas-usage-reporting", flag_descriptions::kSaasUsageReportingName,
      flag_descriptions::kSaasUsageReportingDescription,
      kOsLinux | kOsMac | kOsWin,
