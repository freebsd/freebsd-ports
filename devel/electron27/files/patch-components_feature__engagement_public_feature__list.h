--- components/feature_engagement/public/feature_list.h.orig	2023-10-19 19:58:18 UTC
+++ components/feature_engagement/public/feature_list.h
@@ -259,7 +259,7 @@ DEFINE_VARIATION_PARAM(kIPHiOSPromoPasswordManagerWidg
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHAutofillFeedbackNewBadgeFeature,
                        "IPH_AutofillFeedbackNewBadge");
 DEFINE_VARIATION_PARAM(kIPHBatterySaverModeFeature, "IPH_BatterySaverMode");
@@ -335,7 +335,8 @@ DEFINE_VARIATION_PARAM(kIPHBackNavigationMenuFeature, 
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 DEFINE_VARIATION_PARAM(kIPHAutofillExternalAccountProfileSuggestionFeature,
                        "IPH_AutofillExternalAccountProfileSuggestion");
 DEFINE_VARIATION_PARAM(kIPHAutofillVirtualCardCVCSuggestionFeature,
@@ -541,7 +542,7 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         VARIATION_ENTRY(kIPHiOSPromoPostRestoreDefaultBrowserFeature),
         VARIATION_ENTRY(kIPHiOSPromoPasswordManagerWidgetFeature),
 #elif BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
         VARIATION_ENTRY(kIPHAutofillFeedbackNewBadgeFeature),
         VARIATION_ENTRY(kIPHBatterySaverModeFeature),
         VARIATION_ENTRY(kIPHCompanionSidePanelFeature),
@@ -589,7 +590,8 @@ constexpr flags_ui::FeatureEntry::FeatureVariation
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
         VARIATION_ENTRY(kIPHAutofillExternalAccountProfileSuggestionFeature),
         VARIATION_ENTRY(kIPHAutofillVirtualCardCVCSuggestionFeature),
         VARIATION_ENTRY(kIPHAutofillVirtualCardSuggestionFeature),
