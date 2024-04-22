--- components/feature_engagement/public/feature_constants.cc.orig	2023-11-29 21:39:58 UTC
+++ components/feature_engagement/public/feature_constants.cc
@@ -21,7 +21,7 @@ BASE_FEATURE(kIPHDummyFeature, "IPH_Dummy", base::FEAT
 BASE_FEATURE(kIPHDummyFeature, "IPH_Dummy", base::FEATURE_DISABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIPHBatterySaverModeFeature,
              "IPH_BatterySaverMode",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -560,7 +560,7 @@ constexpr base::FeatureParam<int> kDefaultBrowserEligi
     /*default_value=*/365};
 #endif  // BUILDFLAG(IS_IOS)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD) || \
     BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
 BASE_FEATURE(kIPHAutofillExternalAccountProfileSuggestionFeature,
              "IPH_AutofillExternalAccountProfileSuggestion",
