--- chrome/browser/about_flags.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/about_flags.cc
@@ -256,7 +256,7 @@
 #include "extensions/common/extension_features.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)  
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -342,7 +342,7 @@
 #include "device/vr/public/cpp/switches.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/public/ozone_switches.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
@@ -352,7 +352,7 @@
 #include "chrome/browser/win/mica_titlebar.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/contextual_cueing/contextual_cueing_features.h"  // nogncheck
 #include "chrome/browser/enterprise/profile_management/profile_management_features.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
@@ -363,7 +363,7 @@
 #include "components/user_education/common/user_education_features.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/ui/ui_features.h"
 #include "ui/base/ui_base_features.h"
 #endif
@@ -518,7 +518,7 @@ const FeatureEntry::FeatureVariation kDXGIWaitableSwap
     {"Max 3 Frames", &kDXGIWaitableSwapChain3Frames, 1, nullptr}};
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::Choice kOzonePlatformHintRuntimeChoices[] = {
     {flag_descriptions::kOzonePlatformHintChoiceDefault, "", ""},
     {flag_descriptions::kOzonePlatformHintChoiceAuto,
@@ -819,6 +819,26 @@ const FeatureEntry::FeatureVariation
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
@@ -1223,7 +1243,7 @@ const FeatureEntry::FeatureVariation kPageContentAnnot
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kHistoryEmbeddingsAtKeywordAcceleration[]{
     {"AtKeywordAcceleration", "true"},
 };
@@ -1261,7 +1281,7 @@ const FeatureEntry::FeatureVariation kRemotePageMetada
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 
 // A limited number of combinations of the rich autocompletion params.
 const FeatureEntry::FeatureParam
@@ -1801,7 +1821,7 @@ const FeatureEntry::FeatureVariation kTabScrollingVari
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kTabstripDeclutterQuickModeParams[] = {
     {"stale_threshold_duration", "10s"},
     {"declutter_timer_interval", "10s"},
@@ -3593,7 +3613,7 @@ const FeatureEntry::FeatureVariation
 #endif  // BUILDFLAG(IS_ANDROID)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOn[] =
     {{"link_capturing_state", "on_by_default"}};
 const flags_ui::FeatureEntry::FeatureParam kPwaNavigationCapturingDefaultOff[] =
@@ -4107,7 +4127,7 @@ const FeatureEntry::FeatureVariation kSkiaGraphiteVari
      std::size(kSkiaGraphite_DebugLabelsEnabled), nullptr},
 };
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kTranslationAPI_SkipLanguagePackLimit[] = {
     {"TranslationAPIAcceptLanguagesCheck", "false"},
     {"TranslationAPILimitLanguagePackCount", "false"}};
@@ -4177,7 +4197,7 @@ const FeatureEntry::FeatureVariation
          1, nullptr},
 };
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kContextualCueingEnabledNoEngagementCap[] = {
     {"BackoffTime", "0h"},
     {"BackoffMultiplierBase", "0.0"},
@@ -4962,7 +4982,7 @@ const FeatureEntry kFeatureEntries[] = {
     },
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {
         "fluent-overlay-scrollbars",
         flag_descriptions::kFluentOverlayScrollbarsName,
@@ -5505,7 +5525,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kWebShare)},
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"pulseaudio-loopback-for-cast",
      flag_descriptions::kPulseaudioLoopbackForCastName,
      flag_descriptions::kPulseaudioLoopbackForCastDescription, kOsLinux,
@@ -5541,9 +5561,19 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kWaylandLinuxDrmSyncobjName,
      flag_descriptions::kWaylandLinuxDrmSyncobjDescription, kOsLinux,
      FEATURE_VALUE_TYPE(features::kWaylandLinuxDrmSyncobj)},
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
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {"skip-undecryptable-passwords",
      flag_descriptions::kSkipUndecryptablePasswordsName,
      flag_descriptions::kSkipUndecryptablePasswordsDescription,
@@ -6439,7 +6469,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "MlUrlScoring")},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"omnibox-domain-suggestions",
      flag_descriptions::kOmniboxDomainSuggestionsName,
      flag_descriptions::kOmniboxDomainSuggestionsDescription, kOsDesktop,
@@ -6637,7 +6667,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "OrganicRepeatableQueries")},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"history-embeddings", flag_descriptions::kHistoryEmbeddingsName,
      flag_descriptions::kHistoryEmbeddingsDescription, kOsDesktop,
      FEATURE_WITH_PARAMS_VALUE_TYPE(history_embeddings::kHistoryEmbeddings,
@@ -7176,7 +7206,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(printing::features::kAddPrinterViaPrintscanmgr)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {"cups-ipp-printing-backend",
      flag_descriptions::kCupsIppPrintingBackendName,
      flag_descriptions::kCupsIppPrintingBackendDescription, kOsDesktop,
@@ -7444,7 +7474,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kSupportToolScreenshotDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kSupportToolScreenshot)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {"wasm-tts-component-updater-enabled",
      flag_descriptions::kWasmTtsComponentUpdaterEnabledName,
      flag_descriptions::kWasmTtsComponentUpdaterEnabledDescription, kOsDesktop,
@@ -8108,7 +8138,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(media::kGlobalMediaControlsUpdatedUI)},
 #endif  // !BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-network-service-sandbox",
      flag_descriptions::kEnableNetworkServiceSandboxName,
      flag_descriptions::kEnableNetworkServiceSandboxDescription,
@@ -8786,7 +8816,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(ash::features::kWallpaperGooglePhotosSharedAlbums)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-get-all-screens-media", flag_descriptions::kGetAllScreensMediaName,
      flag_descriptions::kGetAllScreensMediaDescription, kOsCrOS | kOsLinux,
      FEATURE_VALUE_TYPE(blink::features::kGetAllScreensMedia)},
@@ -8813,7 +8843,7 @@ const FeatureEntry kFeatureEntries[] = {
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
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
@@ -9966,7 +9996,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsDesktop | kOsAndroid,
      FEATURE_VALUE_TYPE(features::kProcessPerSiteUpToMainFrameThreshold)},
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"camera-mic-effects", flag_descriptions::kCameraMicEffectsName,
      flag_descriptions::kCameraMicEffectsDescription,
      static_cast<unsigned short>(kOsMac | kOsWin | kOsLinux),
@@ -9992,7 +10022,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "RenderDocument")},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-search-aggregator-policy",
      flag_descriptions::kEnableSearchAggregatorPolicyName,
      flag_descriptions::kEnableSearchAggregatorPolicyDescription,
@@ -10099,7 +10129,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(chrome::android::kReadAloudTapToSeek)},
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"third-party-profile-management",
      flag_descriptions::kThirdPartyProfileManagementName,
      flag_descriptions::kThirdPartyProfileManagementDescription,
@@ -10134,7 +10164,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"enable-user-navigation-capturing-pwa",
      flag_descriptions::kPwaNavigationCapturingName,
      flag_descriptions::kPwaNavigationCapturingDescription,
@@ -10935,7 +10965,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kCanvasHibernationDescription, kOsAll,
      FEATURE_VALUE_TYPE(blink::features::kCanvas2DHibernation)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"sync-enable-bookmarks-in-transport-mode",
      flag_descriptions::kSyncEnableBookmarksInTransportModeName,
      flag_descriptions::kSyncEnableBookmarksInTransportModeDescription,
@@ -11026,7 +11056,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"tab-organization", flag_descriptions::kTabOrganizationName,
      flag_descriptions::kTabOrganizationDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kTabOrganization)},
@@ -11074,7 +11104,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(switches::kForceSupervisedSigninWithCapabilities)},
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
     {"supervised-profile-safe-search",
      flag_descriptions::kSupervisedProfileSafeSearchName,
      flag_descriptions::kSupervisedProfileSafeSearchDescription,
@@ -11318,7 +11348,7 @@ const FeatureEntry kFeatureEntries[] = {
          segmentation_platform::features::kSegmentationSurveyPage)},
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     {"autofill-enable-buy-now-pay-later-for-affirm",
      flag_descriptions::kAutofillEnableBuyNowPayLaterForAffirmName,
      flag_descriptions::kAutofillEnableBuyNowPayLaterForAffirmDescription,
@@ -11447,7 +11477,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          autofill::features::kAutofillEnableCardInfoRuntimeRetrieval)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"translation-api", flag_descriptions::kTranslationAPIName,
      flag_descriptions::kTranslationAPIDescription, kOsMac | kOsWin | kOsLinux,
      FEATURE_WITH_PARAMS_VALUE_TYPE(blink::features::kTranslationAPI,
@@ -11484,7 +11514,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(
          password_manager::features::kPasswordFormClientsideClassifier)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"contextual-cueing", flag_descriptions::kContextualCueingName,
      flag_descriptions::kContextualCueingDescription,
      kOsLinux | kOsMac | kOsWin,
@@ -11778,7 +11808,7 @@ const FeatureEntry kFeatureEntries[] = {
      kOsMac | kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(switches::kEnableSnackbarInSettings)},
 
-#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"automatic-usb-detach", flag_descriptions::kAutomaticUsbDetachName,
      flag_descriptions::kAutomaticUsbDetachDescription, kOsAndroid | kOsLinux,
      FEATURE_VALUE_TYPE(features::kAutomaticUsbDetach)},
