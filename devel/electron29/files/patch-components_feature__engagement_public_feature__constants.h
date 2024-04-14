--- components/feature_engagement/public/feature_constants.h.orig	2024-02-21 00:20:41 UTC
+++ components/feature_engagement/public/feature_constants.h
@@ -25,7 +25,7 @@ BASE_DECLARE_FEATURE(kIPHDummyFeature);
 BASE_DECLARE_FEATURE(kIPHDummyFeature);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHBatterySaverModeFeature);
 BASE_DECLARE_FEATURE(kIPHCompanionSidePanelFeature);
 BASE_DECLARE_FEATURE(kIPHCompanionSidePanelRegionSearchFeature);
@@ -252,7 +252,7 @@ extern const base::FeatureParam<int>
     kDefaultBrowserEligibilitySlidingWindowParam;
 #endif  // BUILDFLAG(IS_IOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
 BASE_DECLARE_FEATURE(kIPHAutofillExternalAccountProfileSuggestionFeature);
 BASE_DECLARE_FEATURE(kIPHAutofillVirtualCardCVCSuggestionFeature);
@@ -300,7 +300,7 @@ BASE_DECLARE_FEATURE(kIPHScalableIphGamingFeature);
 BASE_DECLARE_FEATURE(kIPHScalableIphGamingFeature);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 BASE_DECLARE_FEATURE(kIPHDesktopPWAsLinkCapturingLaunch);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
 
