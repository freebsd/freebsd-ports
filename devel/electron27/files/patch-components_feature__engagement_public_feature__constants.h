--- components/feature_engagement/public/feature_constants.h.orig	2023-10-19 19:58:18 UTC
+++ components/feature_engagement/public/feature_constants.h
@@ -23,7 +23,7 @@ BASE_DECLARE_FEATURE(kUseClientConfigIPH);
 BASE_DECLARE_FEATURE(kIPHDummyFeature);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHAutofillFeedbackNewBadgeFeature);
 BASE_DECLARE_FEATURE(kIPHBatterySaverModeFeature);
 BASE_DECLARE_FEATURE(kIPHCompanionSidePanelFeature);
@@ -211,7 +211,8 @@ BASE_DECLARE_FEATURE(kIPHiOSPromoPasswordManagerWidget
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHAutofillExternalAccountProfileSuggestionFeature);
 BASE_DECLARE_FEATURE(kIPHAutofillVirtualCardCVCSuggestionFeature);
 BASE_DECLARE_FEATURE(kIPHAutofillVirtualCardSuggestionFeature);
