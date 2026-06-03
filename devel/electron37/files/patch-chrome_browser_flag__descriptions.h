--- chrome/browser/flag_descriptions.h.orig	2025-07-21 19:32:31 UTC
+++ chrome/browser/flag_descriptions.h
@@ -413,7 +413,7 @@ extern const char
     kAutofillEnableAllowlistForBmoCardCategoryBenefitsDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kAutofillEnableAmountExtractionAllowlistDesktopName[];
 extern const char kAutofillEnableAmountExtractionAllowlistDesktopDescription[];
 extern const char kAutofillEnableAmountExtractionDesktopName[];
@@ -424,7 +424,7 @@ extern const char kAutofillEnableAmountExtractionDeskt
         // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kAutofillEnableBuyNowPayLaterName[];
 extern const char kAutofillEnableBuyNowPayLaterDescription[];
 
@@ -656,7 +656,7 @@ extern const char kContextMenuEmptySpaceDescription[];
 extern const char kContextMenuEmptySpaceDescription[];
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kContextualCueingName[];
 extern const char kContextualCueingDescription[];
 extern const char kGlicZeroStateSuggestionsName[];
@@ -847,7 +847,7 @@ extern const char kDevicePostureDescription[];
 extern const char kDevicePostureDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kDocumentPictureInPictureAnimateResizeName[];
 extern const char kDocumentPictureInPictureAnimateResizeDescription[];
 
@@ -1006,7 +1006,7 @@ extern const char kEnableIsolatedWebAppDevModeDescript
 extern const char kEnableIsolatedWebAppDevModeName[];
 extern const char kEnableIsolatedWebAppDevModeDescription[];
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kEnableIwaKeyDistributionComponentName[];
 extern const char kEnableIwaKeyDistributionComponentDescription[];
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -2079,7 +2079,7 @@ extern const char kRetainOmniboxOnFocusDescription[];
 extern const char kRetainOmniboxOnFocusDescription[];
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kRootScrollbarFollowsTheme[];
 extern const char kRootScrollbarFollowsThemeDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
@@ -2226,7 +2226,7 @@ extern const char kDefaultSiteInstanceGroupsDescriptio
 extern const char kDefaultSiteInstanceGroupsDescription[];
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kPwaNavigationCapturingName[];
 extern const char kPwaNavigationCapturingDescription[];
 #endif
@@ -2386,7 +2386,7 @@ extern const char kTranslateForceTriggerOnEnglishDescr
 extern const char kTranslateForceTriggerOnEnglishName[];
 extern const char kTranslateForceTriggerOnEnglishDescription[];
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kEnableHistorySyncOptinName[];
 extern const char kEnableHistorySyncOptinDescription[];
 
@@ -2641,7 +2641,7 @@ extern const char kReduceTransferSizeUpdatedIPCDescrip
 extern const char kReduceTransferSizeUpdatedIPCName[];
 extern const char kReduceTransferSizeUpdatedIPCDescription[];
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kReduceUserAgentDataLinuxPlatformVersionName[];
 extern const char kReduceUserAgentDataLinuxPlatformVersionDescription[];
 #endif  // #if BUILDFLAG(IS_LINUX)
@@ -3432,7 +3432,7 @@ extern const char kTranslateOpenSettingsDescription[];
 extern const char kTranslateOpenSettingsDescription[];
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kWasmTtsComponentUpdaterEnabledName[];
 extern const char kWasmTtsComponentUpdaterEnabledDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
@@ -4632,7 +4632,7 @@ extern const char kTetheringExperimentalFunctionalityD
 
 #endif  // #if BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kGetAllScreensMediaName[];
 extern const char kGetAllScreensMediaDescription[];
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
@@ -4767,7 +4767,7 @@ extern const char kEnableArmHwdrmDescription[];
 
 // Linux ---------------------------------------------------------------------
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 extern const char kOzonePlatformHintChoiceDefault[];
 extern const char kOzonePlatformHintChoiceAuto[];
 extern const char kOzonePlatformHintChoiceX11[];
@@ -4798,6 +4798,9 @@ extern const char kWaylandUiScalingDescription[];
 
 extern const char kWaylandUiScalingName[];
 extern const char kWaylandUiScalingDescription[];
+
+extern const char kAudioBackendName[];
+extern const char kAudioBackendDescription[];
 #endif  // BUILDFLAG(IS_LINUX)
 
 // Random platform combinations -----------------------------------------------
@@ -4812,7 +4815,7 @@ extern const char kWebBluetoothConfirmPairingSupportDe
 extern const char kWebBluetoothConfirmPairingSupportDescription[];
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 #if BUILDFLAG(ENABLE_PRINTING)
 extern const char kCupsIppPrintingBackendName[];
 extern const char kCupsIppPrintingBackendDescription[];
@@ -4825,7 +4828,7 @@ extern const char kScreenlockReauthCardDescription[];
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kFollowingFeedSidepanelName[];
 extern const char kFollowingFeedSidepanelDescription[];
 
@@ -4842,7 +4845,7 @@ extern const char kTaskManagerDesktopRefreshDescriptio
 extern const char kTaskManagerDesktopRefreshDescription[];
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 extern const char kEnableNetworkServiceSandboxName[];
 extern const char kEnableNetworkServiceSandboxDescription[];
 
@@ -4934,7 +4937,7 @@ extern const char kElementCaptureDescription[];
 extern const char kElementCaptureDescription[];
 #endif  // !BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 extern const char kUIDebugToolsName[];
 extern const char kUIDebugToolsDescription[];
 #endif
@@ -4973,7 +4976,7 @@ extern const char kComposeUpfrontInputModesDescription
 extern const char kComposeUpfrontInputModesDescription[];
 #endif  // BUILDFLAG(ENABLE_COMPOSE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kThirdPartyProfileManagementName[];
 extern const char kThirdPartyProfileManagementDescription[];
 
@@ -5047,7 +5050,7 @@ extern const char kSupervisedUserBlockInterstitialV3De
 extern const char kSupervisedUserBlockInterstitialV3Name[];
 extern const char kSupervisedUserBlockInterstitialV3Description[];
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 extern const char kSupervisedProfileHideGuestName[];
 extern const char kSupervisedProfileHideGuestDescription[];
 
