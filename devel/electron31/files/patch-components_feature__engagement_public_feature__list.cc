--- components/feature_engagement/public/feature_list.cc.orig	2024-06-18 21:43:28 UTC
+++ components/feature_engagement/public/feature_list.cc
@@ -148,7 +148,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHiOSInlineEnhancedSafeBrowsingPromoFeature,
 #endif  // BUILDFLAG(IS_IOS)
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     &kEsbDownloadRowPromoFeature,
     &kIPHBatterySaverModeFeature,
     &kIPHCompanionSidePanelFeature,
@@ -211,7 +211,8 @@ const base::Feature* const kAllFeatures[] = {
         // BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
     &kIPHAutofillCreditCardBenefitFeature,
     &kIPHAutofillExternalAccountProfileSuggestionFeature,
     &kIPHAutofillManualFallbackFeature,
@@ -260,7 +261,7 @@ const base::Feature* const kAllFeatures[] = {
     &kIPHScalableIphGamingFeature,
 #endif  // BUILDFLAG(IS_CHROMEOS_ASH)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
     &kIPHDesktopPWAsLinkCapturingLaunch,
 #endif  // BUILDFLAG(IS_WIN) ||  BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
