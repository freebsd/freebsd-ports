--- components/feature_engagement/public/feature_constants.cc.orig	2024-04-15 20:33:54 UTC
+++ components/feature_engagement/public/feature_constants.cc
@@ -18,7 +18,7 @@ BASE_FEATURE(kIPHDummyFeature, "IPH_Dummy", base::FEAT
 BASE_FEATURE(kIPHDummyFeature, "IPH_Dummy", base::FEATURE_DISABLED_BY_DEFAULT);
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIPHBatterySaverModeFeature,
              "IPH_BatterySaverMode",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -584,7 +584,8 @@ BASE_FEATURE(kDefaultBrowserTriggerCriteriaExperiment,
 #endif  // BUILDFLAG(IS_IOS)
 
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_APPLE) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA) || \
+    BUILDFLAG(IS_BSD)
 BASE_FEATURE(kIPHAutofillExternalAccountProfileSuggestionFeature,
              "IPH_AutofillExternalAccountProfileSuggestion",
              base::FEATURE_ENABLED_BY_DEFAULT);
@@ -712,7 +713,7 @@ BASE_FEATURE(kIPHScalableIphGamingFeature,
              base::FEATURE_DISABLED_BY_DEFAULT);
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 // This can be enabled by default, as the DesktopPWAsLinkCapturing
 // flag is needed for the IPH linked to this feature to work, and
 // use-cases to show the IPH are guarded by that flag.
