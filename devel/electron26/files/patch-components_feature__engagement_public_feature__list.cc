--- components/feature_engagement/public/feature_list.cc.orig	2023-08-10 01:48:40 UTC
+++ components/feature_engagement/public/feature_list.cc
@@ -139,7 +139,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHiOSPromoPostRestoreDefaultBrowserFeature,
 #endif  // BUILDFLAG(IS_IOS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     &kIPHAutofillFeedbackNewBadgeFeature,
     &kIPHBatterySaverModeFeature,
     &kIPHCompanionSidePanelFeature,
@@ -182,7 +182,8 @@ const base::Feature* const kAllFeatures[] = {
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
     &kIPHAutofillExternalAccountProfileSuggestionFeature,
     &kIPHAutofillVirtualCardSuggestionFeature,
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) ||
