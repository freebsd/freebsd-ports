--- chrome/browser/about_flags.cc.orig	2025-05-25 23:46:57 UTC
+++ chrome/browser/about_flags.cc
@@ -260,7 +260,7 @@
 #include "extensions/common/extension_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)  
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -349,7 +349,7 @@
 #include "device/vr/public/cpp/switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/public/ozone_switches.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -359,7 +359,7 @@
 #include "chrome/browser/win/mica_titlebar.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/contextual_cueing/contextual_cueing_features.h"  // nogncheck
 #include "chrome/browser/enterprise/profile_management/profile_management_features.h"
 #include "chrome/browser/enterprise/webstore/features.h"
@@ -371,7 +371,7 @@
 #include "components/user_education/common/user_education_features.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/ui_features.h"
 #include "ui/base/ui_base_features.h"
 #endif
@@ -423,7 +423,7 @@ const FeatureEntry::Choice kPullToRefreshChoices[] = {
 #endif  // USE_AURA
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 
 const FeatureEntry::FeatureParam kLocalNetworkAccessChecksBlock[] = {
     {"LocalNetworkAccessChecksWarn", "false"}};
@@ -539,7 +539,7 @@ const FeatureEntry::FeatureVariation kDXGIWaitableSwap
     {"Max 3 Frames", &kDXGIWaitableSwapChain3Frames, 1, nullptr}};
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::Choice kOzonePlatformHintRuntimeChoices[] = {
     {flag_descriptions::kOzonePlatformHintChoiceDefault, "", ""},
     {flag_descriptions::kOzonePlatformHintChoiceAuto,
@@ -852,6 +852,26 @@ const FeatureEntry::FeatureVariation
          std::size(kWebIdentityDigitalIdentityCredentialHighRiskDialogParam),
          nullptr}};
 
+#if BUILDFLAG(IS_BSD)
+const FeatureEntry::FeatureParam kAudioBackendPulseAudio[] = {
+        { "audio-backend", "pulseaudio" }};
+const FeatureEntry::FeatureParam kAudioBackendSndio[] = {
+        { "audio-backend", "sndio" }};
+const FeatureEntry::FeatureParam kAudioBackendAlsa[] = {
+        { "audio-backend", "alsa" }};
+const FeatureEntry::FeatureVariation
+    kAudioBackendVariations[] = {
+        {"using PulseAudio by default if available", kAudioBackendPulseAudio,
+         std::size(kAudioBackendPulseAudio),
+         nullptr},
+        {"using sndio by default if available", kAudioBackendSndio,
+         std::size(kAudioBackendSndio),
+         nullptr},
+        {"using ALSA by default if available", kAudioBackendAlsa,
+         std::size(kAudioBackendAlsa),
+         nullptr}};
+#endif
+
 const FeatureEntry::FeatureParam kClipboardMaximumAge60Seconds[] = {
     {"UIClipboardMaximumAge", "60"}};
 const FeatureEntry::FeatureParam kClipboardMaximumAge90Seconds[] = {
@@ -1227,7 +1247,7 @@ constexpr FeatureEntry::FeatureVariation
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kHistoryEmbeddingsAtKeywordAcceleration[]{
     {"AtKeywordAcceleration", "true"},
 };
@@ -1265,7 +1285,7 @@ const FeatureEntry::FeatureVariation kRemotePageMetada
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 // A limited number of combinations of the rich autocompletion params.
 const FeatureEntry::FeatureParam kOmniboxRichAutocompletionAggressive1[] = {
@@ -3555,7 +3575,7 @@ const FeatureEntry::FeatureVariation
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOn[] =
     {{"link_capturing_state", "on_by_default"}};
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOff[] =
@@ -4059,7 +4079,7 @@ const FeatureEntry::FeatureVariation kSkiaGraphiteVari
      std::size(kSkiaGraphite_DebugLabelsEnabled), nullptr},
 };
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kTranslationAPI_SkipLanguagePackLimit[] = {
     {"TranslationAPIAcceptLanguagesCheck", "false"},
     {"TranslationAPILimitLanguagePackCount", "false"}};
@@ -4125,7 +4145,7 @@ const FeatureEntry::FeatureVariation
          1, nullptr},
 };
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kContextualCueingEnabledNoEngagementCap[] = {
     {"BackoffTime", "0h"},
     {"BackoffMultiplierBase", "0.0"},
@@ -4992,7 +5012,7 @@ const FeatureEntry kFeatureEntries[] = {
     },
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {
         "fluent-overlay-scrollbars",
         flag_descriptions::kFluentOverlayScrollbarsName,
@@ -5279,7 +5299,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableIsolatedWebAppDevModeName,
      flag_descriptions::kEnableIsolatedWebAppDevModeDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kIsolatedWebAppDevMode)},
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-iwa-key-distribution-component",
      flag_descriptions::kEnableIwaKeyDistributionComponentName,
      flag_descriptions::kEnableIwaKeyDistributionComponentDescription,
@@ -5500,7 +5520,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kWebShare)},
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"pulseaudio-loopback-for-cast",
      flag_descriptions::kPulseaudioLoopbackForCastName,
      flag_descriptions::kPulseaudioLoopbackForCastDescription, kOsLinux,
@@ -5541,6 +5561,16 @@ const FeatureEntry kFeatureEntries[] = {
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
@@ -6427,7 +6457,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "MlUrlScoring")},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"lens-overlay-omnibox-entry-point",
      flag_descriptions::kLensOverlayOmniboxEntryPointName,
      flag_descriptions::kLensOverlayOmniboxEntryPointDescription, kOsDesktop,
@@ -6702,7 +6732,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     kNumSrpZpsRelatedSearches,
                                     "PowerTools")},
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"history-embeddings", flag_descriptions::kHistoryEmbeddingsName,
      flag_descriptions::kHistoryEmbeddingsDescription, kOsDesktop,
      FEATURE_WITH_PARAMS_VALUE_TYPE(history_embeddings::kHistoryEmbeddings,
@@ -7194,7 +7224,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(printing::features::kAddPrinterViaPrintscanmgr)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {"cups-ipp-printing-backend",
      flag_descriptions::kCupsIppPrintingBackendName,
      flag_descriptions::kCupsIppPrintingBackendDescription, kOsDesktop,
@@ -7442,7 +7472,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSupportToolScreenshotDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kSupportToolScreenshot)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {"wasm-tts-component-updater-enabled",
      flag_descriptions::kWasmTtsComponentUpdaterEnabledName,
      flag_descriptions::kWasmTtsComponentUpdaterEnabledDescription, kOsDesktop,
@@ -8114,7 +8144,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kGlobalMediaControlsUpdatedUI)},
 #endif  // !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-network-service-sandbox",
      flag_descriptions::kEnableNetworkServiceSandboxName,
      flag_descriptions::kEnableNetworkServiceSandboxDescription,
@@ -8779,7 +8809,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kWallpaperGooglePhotosSharedAlbums)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-get-all-screens-media", flag_descriptions::kGetAllScreensMediaName,
      flag_descriptions::kGetAllScreensMediaDescription, kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(blink::features::kGetAllScreensMedia)},
@@ -8804,7 +8834,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kGlobalVaapiLockDescription, kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(media::kGlobalVaapiLock)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {
         "ui-debug-tools",
         flag_descriptions::kUIDebugToolsName,
@@ -9280,7 +9310,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kRenderPassDrawnRect)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"media-session-enter-picture-in-picture",
      flag_descriptions::kMediaSessionEnterPictureInPictureName,
      flag_descriptions::kMediaSessionEnterPictureInPictureDescription,
@@ -9929,7 +9959,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsDesktop | kOsAndroid,
      FEATURE_VALUE_TYPE(features::kProcessPerSiteUpToMainFrameThreshold)},
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"camera-mic-effects", flag_descriptions::kCameraMicEffectsName,
      flag_descriptions::kCameraMicEffectsDescription,
      static_cast<unsigned short>(kOsMac | kOsWin | kOsLinux),
@@ -10053,7 +10083,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chrome::android::kReadAloudTapToSeek)},
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"third-party-profile-management",
      flag_descriptions::kThirdPartyProfileManagementName,
      flag_descriptions::kThirdPartyProfileManagementDescription,
@@ -10082,7 +10112,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-user-navigation-capturing-pwa",
      flag_descriptions::kPwaNavigationCapturingName,
      flag_descriptions::kPwaNavigationCapturingDescription,
@@ -10822,7 +10852,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kCanvasHibernationDescription, kOsAll,
      FEATURE_VALUE_TYPE(blink::features::kCanvas2DHibernation)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-history-sync-optin",
      flag_descriptions::kEnableHistorySyncOptinName,
      flag_descriptions::kEnableHistorySyncOptinDescription,
@@ -10925,7 +10955,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(switches::kForceSupervisedSigninWithCapabilities)},
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"supervised-profile-safe-search",
      flag_descriptions::kSupervisedProfileSafeSearchName,
      flag_descriptions::kSupervisedProfileSafeSearchDescription,
@@ -11172,7 +11202,7 @@ const FeatureEntry kFeatureEntries[] = {
          segmentation_platform::features::kSegmentationSurveyPage)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later",
      flag_descriptions::kAutofillEnableBuyNowPayLaterName,
      flag_descriptions::kAutofillEnableBuyNowPayLaterDescription, kOsDesktop,
@@ -11287,7 +11317,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          autofill::features::kAutofillEnableCardInfoRuntimeRetrieval)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"translation-api", flag_descriptions::kTranslationAPIName,
      flag_descriptions::kTranslationAPIDescription, kOsMac | kOsWin | kOsLinux,
      FEATURE_WITH_PARAMS_VALUE_TYPE(blink::features::kTranslationAPI,
@@ -11324,7 +11354,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          password_manager::features::kPasswordFormClientsideClassifier)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"contextual-cueing", flag_descriptions::kContextualCueingName,
      flag_descriptions::kContextualCueingDescription,
      kOsLinux | kOsMac | kOsWin,
@@ -11658,7 +11688,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ui::kUseNewEtc1Encoder)},
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"automatic-usb-detach", flag_descriptions::kAutomaticUsbDetachName,
      flag_descriptions::kAutomaticUsbDetachDescription, kOsAndroid | kOsLinux,
      FEATURE_VALUE_TYPE(features::kAutomaticUsbDetach)},
@@ -11708,7 +11738,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // !BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction-desktop",
      flag_descriptions::kAutofillEnableAmountExtractionDesktopName,
      flag_descriptions::kAutofillEnableAmountExtractionDesktopDescription,
@@ -11728,7 +11758,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(blink::features::kClipboardContentsId)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction-allowlist-desktop",
      flag_descriptions::kAutofillEnableAmountExtractionAllowlistDesktopName,
      flag_descriptions::
@@ -11839,7 +11869,7 @@ const FeatureEntry kFeatureEntries[] = {
          apps::chrome_app_deprecation::kAllowUserInstalledChromeApps)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"chrome-web-store-navigation-throttle",
      flag_descriptions::kChromeWebStoreNavigationThrottleName,
      flag_descriptions::kChromeWebStoreNavigationThrottleDescription,
@@ -11874,7 +11904,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"autofill-enable-amount-extraction-desktop-logging",
      flag_descriptions::kAutofillEnableAmountExtractionDesktopLoggingName,
      flag_descriptions::
@@ -11904,7 +11934,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kEnableWebAppUpdateTokenParsingDescription, kOsAll,
      FEATURE_VALUE_TYPE(features::kWebAppEnableUpdateTokenParsing)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"root-scrollbar-follows-browser-theme",
      flag_descriptions::kRootScrollbarFollowsTheme,
      flag_descriptions::kRootScrollbarFollowsThemeDescription,
@@ -11926,7 +11956,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"local-network-access-check",
      flag_descriptions::kLocalNetworkAccessChecksName,
      flag_descriptions::kLocalNetworkAccessChecksDescription, kOsDesktop,
