--- chrome/browser/about_flags.cc.orig	2022-09-24 10:57:32 UTC
+++ chrome/browser/about_flags.cc
@@ -212,7 +212,7 @@
 #include "ui/native_theme/native_theme_features.h"
 #include "ui/ui_features.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)  
 #include "base/allocator/buildflags.h"
 #endif
 
@@ -287,7 +287,7 @@
 #include "chrome/browser/supervised_user/supervised_user_features/supervised_user_features.h"  // nogncheck
 #endif  // ENABLE_SUPERVISED_USERS
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
 #include "ui/ozone/buildflags.h"
 #include "ui/ozone/public/ozone_switches.h"
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_ASH)
@@ -392,7 +392,7 @@ const FeatureEntry::FeatureVariation kDXGIWaitableSwap
     {"Max 3 Frames", &kDXGIWaitableSwapChain3Frames, 1, nullptr}};
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 const FeatureEntry::Choice kOzonePlatformHintRuntimeChoices[] = {
     {flag_descriptions::kOzonePlatformHintChoiceDefault, "", ""},
     {flag_descriptions::kOzonePlatformHintChoiceAuto,
@@ -1262,7 +1262,7 @@ const FeatureEntry::FeatureVariation
 };
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 const FeatureEntry::FeatureParam kOmniboxDocumentProviderServerScoring[] = {
     {"DocumentUseServerScore", "true"},
     {"DocumentUseClientScore", "false"},
@@ -3923,7 +3923,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(base::kOneGroupPerRenderer)},
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {
         "enable-accelerated-video-decode",
         flag_descriptions::kAcceleratedVideoDecodeName,
@@ -4549,7 +4549,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(features::kWebShare)},
 #endif  // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"ozone-platform-hint", flag_descriptions::kOzonePlatformHintName,
      flag_descriptions::kOzonePlatformHintDescription, kOsLinux,
      MULTI_VALUE_TYPE(kOzonePlatformHintRuntimeChoices)},
@@ -4568,7 +4568,7 @@ const FeatureEntry kFeatureEntries[] = {
          password_manager::features::kForceInitialSyncWhenDecryptionFails)},
 #endif  // BUILDFLAG(IS_LINUX)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     {"skip-undecryptable-passwords",
      flag_descriptions::kSkipUndecryptablePasswordsName,
      flag_descriptions::kSkipUndecryptablePasswordsDescription,
@@ -4822,7 +4822,7 @@ const FeatureEntry kFeatureEntries[] = {
                                     "FeedCloseRefresh")},
 #endif  // BUILDFLAG(IS_ANDROID)
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"following-feed-sidepanel", flag_descriptions::kFollowingFeedSidepanelName,
      flag_descriptions::kFollowingFeedSidepanelDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(feed::kWebUiFeed)},
@@ -5336,7 +5336,7 @@ const FeatureEntry kFeatureEntries[] = {
      FEATURE_VALUE_TYPE(omnibox::kZeroSuggestPrefetchingOnWeb)},
 
 #if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_WIN) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"omnibox-experimental-keyword-mode",
      flag_descriptions::kOmniboxExperimentalKeywordModeName,
      flag_descriptions::kOmniboxExperimentalKeywordModeDescription, kOsDesktop,
@@ -5873,7 +5873,7 @@ const FeatureEntry kFeatureEntries[] = {
      flag_descriptions::kPointerLockOptionsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kPointerLockOptions)},
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     {"enable-async-dns", flag_descriptions::kAsyncDnsName,
      flag_descriptions::kAsyncDnsDescription, kOsWin | kOsLinux,
      FEATURE_VALUE_TYPE(features::kAsyncDns)},
@@ -6791,7 +6791,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif  // BUILDFLAG(IS_CHROMEOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"global-media-controls-modern-ui",
      flag_descriptions::kGlobalMediaControlsModernUIName,
      flag_descriptions::kGlobalMediaControlsModernUIDescription,
@@ -7651,7 +7651,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {"quick-commands", flag_descriptions::kQuickCommandsName,
      flag_descriptions::kQuickCommandsDescription, kOsDesktop,
      FEATURE_VALUE_TYPE(features::kQuickCommands)},
@@ -7950,7 +7950,7 @@ const FeatureEntry kFeatureEntries[] = {
 
 #if BUILDFLAG(IS_WIN) ||                                      \
     (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)) || \
-    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_MAC) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     {
         "ui-debug-tools",
         flag_descriptions::kUIDebugToolsName,
@@ -8530,7 +8530,7 @@ const FeatureEntry kFeatureEntries[] = {
 #endif
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-    BUILDFLAG(IS_CHROMEOS_ASH)
+    BUILDFLAG(IS_CHROMEOS_ASH) || BUILDFLAG(IS_BSD)
     {"document-picture-in-picture-api",
      flag_descriptions::kDocumentPictureInPictureApiName,
      flag_descriptions::kDocumentPictureInPictureApiDescription,
