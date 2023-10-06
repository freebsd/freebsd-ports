--- components/feature_engagement/public/feature_constants.h.orig	2023-08-10 01:48:40 UTC
+++ components/feature_engagement/public/feature_constants.h
@@ -23,7 +23,7 @@ BASE_DECLARE_FEATURE(kUseClientConfigIPH);
 BASE_DECLARE_FEATURE(kIPHDummyFeature);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHAutofillFeedbackNewBadgeFeature);
 BASE_DECLARE_FEATURE(kIPHBatterySaverModeFeature);
 BASE_DECLARE_FEATURE(kIPHCompanionSidePanelFeature);
@@ -206,7 +206,8 @@ BASE_DECLARE_FEATURE(kIPHiOSPromoPostRestoreDefaultBro
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHAutofillExternalAccountProfileSuggestionFeature);
 BASE_DECLARE_FEATURE(kIPHAutofillVirtualCardSuggestionFeature);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) ||
