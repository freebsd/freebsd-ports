--- components/feature_engagement/public/feature_list.h.orig	2023-08-10 01:48:40 UTC
+++ components/feature_engagement/public/feature_list.h
@@ -257,7 +257,7 @@ DEFINE_VARIATION_PARAM(kIPHiOSPromoPostRestoreDefaultB
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHAutofillFeedbackNewBadgeFeature,
                        "IPH_AutofillFeedbackNewBadge");
 DEFINE_VARIATION_PARAM(kIPHBatterySaverModeFeature, "IPH_BatterySaverMode");
@@ -325,7 +325,8 @@ DEFINE_VARIATION_PARAM(kIPHBackNavigationMenuFeature, 
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHAutofillExternalAccountProfileSuggestionFeature,
                        "IPH_AutofillExternalAccountProfileSuggestion");
 DEFINE_VARIATION_PARAM(kIPHAutofillVirtualCardSuggestionFeature,
@@ -465,7 +466,7 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         VARIATION_ENTRY(kIPHiOSShareToolbarItemFeature),
         VARIATION_ENTRY(kIPHiOSPromoPostRestoreDefaultBrowserFeature),
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
         VARIATION_ENTRY(kIPHAutofillFeedbackNewBadgeFeature),
         VARIATION_ENTRY(kIPHBatterySaverModeFeature),
         VARIATION_ENTRY(kIPHCompanionSidePanelFeature),
@@ -509,7 +510,8 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
         VARIATION_ENTRY(kIPHAutofillExternalAccountProfileSuggestionFeature),
         VARIATION_ENTRY(kIPHAutofillVirtualCardSuggestionFeature),
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) ||
