--- components/feature_engagement/public/feature_list.cc.orig	2023-10-19 19:58:18 UTC
+++ components/feature_engagement/public/feature_list.cc
@@ -139,7 +139,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHiOSPromoPasswordManagerWidgetFeature,
 #endif  // BUILDFLAG(IS_IOS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     &kIPHAutofillFeedbackNewBadgeFeature,
     &kIPHBatterySaverModeFeature,
     &kIPHCompanionSidePanelFeature,
@@ -186,7 +186,8 @@ const base::Feature* const kAllFeatures[] = {
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
     &kIPHAutofillExternalAccountProfileSuggestionFeature,
     &kIPHAutofillVirtualCardCVCSuggestionFeature,
     &kIPHAutofillVirtualCardSuggestionFeature,
