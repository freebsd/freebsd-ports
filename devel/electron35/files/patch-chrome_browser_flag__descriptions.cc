--- chrome/browser/flag_descriptions.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/flag_descriptions.cc
@@ -521,7 +521,7 @@ const char kAutofillEnableAllowlistForBmoCardCategoryB
     "Autofill suggestions on the allowlisted merchant websites.";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kAutofillEnableAmountExtractionDesktopName[] =
     "Enable checkout amount extraction on Chrome desktop";
 const char kAutofillEnableAmountExtractionDesktopDescription[] =
@@ -530,7 +530,7 @@ const char kAutofillEnableAmountExtractionDesktopDescr
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kAutofillEnableBuyNowPayLaterForAffirmName[] =
     "Enable buy now pay later on Autofill for Affirm";
 const char kAutofillEnableBuyNowPayLaterForAffirmDescription[] =
@@ -961,7 +961,7 @@ const char kDevicePostureDescription[] =
     "Enables Device Posture API (foldable devices)";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kDocumentPictureInPictureAnimateResizeName[] =
     "Document Picture-in-Picture Animate Resize";
 const char kDocumentPictureInPictureAnimateResizeDescription[] =
@@ -1049,7 +1049,7 @@ const char kCompressionDictionaryTransportRequireKnown
     "when the connection is using a well known root cert or when the server is "
     "a localhost.";
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kContextualCueingName[] = "Contextual cueing";
 const char kContextualCueingDescription[] =
     "Enables the contextual cueing system to support showing actions";
@@ -2228,7 +2228,7 @@ const char kContextualPageActionsShareModelDescription
     "Enables share model data collection.";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kEnableSearchAggregatorPolicyName[] =
     "Enable EnterpriseSearchAggregatorSettings policy";
 const char kEnableSearchAggregatorPolicyDescription[] =
@@ -3520,7 +3520,7 @@ const char kDefaultSiteInstanceGroupsDescription[] =
     "SiteInstance.";
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kPwaNavigationCapturingName[] = "Desktop PWA Link Capturing";
 const char kPwaNavigationCapturingDescription[] =
     "Enables opening links from Chrome in an installed PWA. Currently under "
@@ -3758,7 +3758,7 @@ const char kTranslateForceTriggerOnEnglishDescription[
     "Force the Translate Triggering on English pages experiment to be enabled "
     "with the selected language model active.";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kTranslationAPIName[] = "Experimental translation API";
 const char kTranslationAPIDescription[] =
     "Enables the on-device language translation API. "
@@ -5404,7 +5404,7 @@ const char kUserDisplayModeSyncStandaloneMitigationDes
     "Enables a mitigation during web app install on CrOS for syncing "
     "user_display_mode: kStandalone to non-CrOS devices.";
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 const char kWasmTtsComponentUpdaterEnabledName[] =
     "Enable Wasm TTS Extension Component";
 const char kWasmTtsComponentUpdaterEnabledDescription[] =
@@ -7441,7 +7441,7 @@ const char kTetheringExperimentalFunctionalityDescript
 
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kGetAllScreensMediaName[] = "GetAllScreensMedia API";
 const char kGetAllScreensMediaDescription[] =
     "When enabled, the getAllScreensMedia API for capturing multiple screens "
@@ -7671,7 +7671,7 @@ const char kEnableArmHwdrmDescription[] = "Enable HW b
 
 // Linux -----------------------------------------------------------------------
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const char kOzonePlatformHintChoiceDefault[] = "Default";
 const char kOzonePlatformHintChoiceAuto[] = "Auto";
 const char kOzonePlatformHintChoiceX11[] = "X11";
@@ -7717,6 +7717,18 @@ const char kWaylandUiScalingDescription[] =
     "Enable experimental support for text scaling in the Wayland backend "
     "backed by full UI scaling. Requires #wayland-per-window-scaling to be "
     "enabled too.";
+
+#if BUILDFLAG(IS_BSD)
+const char kAudioBackendName[] =
+    "Audio Backend";
+const char kAudioBackendDescription[] =
+#if BUILDFLAG(IS_OPENBSD)
+    "Select the desired audio backend to use. The default is sndio.";
+#elif BUILDFLAG(IS_FREEBSD)
+    "Select the desired audio backend to use. The default will automatically "
+    "enumerate through the supported backends.";
+#endif
+#endif
 #endif  // BUILDFLAG(IS_LINUX)
 
 // Random platform combinations -----------------------------------------------
@@ -7729,7 +7741,7 @@ const char kZeroCopyVideoCaptureDescription[] =
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kFollowingFeedSidepanelName[] = "Following feed in the sidepanel";
 const char kFollowingFeedSidepanelDescription[] =
     "Enables the following feed in the sidepanel.";
@@ -7762,7 +7774,7 @@ const char kTaskManagerDesktopRefreshDescription[] =
     "Enables a refreshed design for the Task Manager on Desktop platforms.";
 #endif  // BUILDFLAG(IS_ANDROID)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
 const char kEnableNetworkServiceSandboxName[] =
     "Enable the network service sandbox.";
 const char kEnableNetworkServiceSandboxDescription[] =
@@ -7794,7 +7806,7 @@ const char kWebBluetoothConfirmPairingSupportDescripti
     "Bluetooth";
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 const char kSkipUndecryptablePasswordsName[] =
     "Skip undecryptable passwords to use the available decryptable "
     "passwords.";
@@ -7944,7 +7956,7 @@ const char kElementCaptureDescription[] =
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 const char kUIDebugToolsName[] = "Debugging tools for UI";
 const char kUIDebugToolsDescription[] =
     "Enables additional keyboard shortcuts to help debugging.";
@@ -8000,7 +8012,7 @@ const char kComposeUpfrontInputModesDescription[] =
     "Enables upfront input modes in the Compose dialog";
 #endif  // BUILDFLAG(ENABLE_COMPOSE)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kThirdPartyProfileManagementName[] =
     "Third party profile management";
 const char kThirdPartyProfileManagementDescription[] =
@@ -8133,7 +8145,7 @@ const char kOverlayScrollbarsOSSettingsDescription[] =
     "Enable the OS settings for overlay scrollbars on ChromeOS.";
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 const char kSupervisedProfileHideGuestName[] = "Supervised Profile Hide Guest";
 const char kSupervisedProfileHideGuestDescription[] =
     "Hides Guest Profile entry points for supervised users";
