--- components/feature_engagement/public/feature_constants.cc.orig	2023-03-30 00:33:48 UTC
+++ components/feature_engagement/public/feature_constants.cc
@@ -19,7 +19,7 @@ BASE_FEATURE(kUseClientConfigIPH,
 BASE_FEATURE(kIPHDummyFeature, "IPH_Dummy", base::FEATURE_DISABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIPHBatterySaverModeFeature,
              "IPH_BatterySaverMode",
              base::FEATURE_DISABLED_BY_DEFAULT);
@@ -437,7 +437,8 @@ BASE_FEATURE(kIPHiOSAppStorePromoFeature,
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIPHAutofillVirtualCardSuggestionFeature,
              "IPH_AutofillVirtualCardSuggestion",
              base::FEATURE_ENABLED_BY_DEFAULT);
