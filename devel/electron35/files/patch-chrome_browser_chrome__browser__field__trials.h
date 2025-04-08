--- chrome/browser/chrome_browser_field_trials.h.orig	2025-01-27 17:37:37 UTC
+++ chrome/browser/chrome_browser_field_trials.h
@@ -33,7 +33,7 @@ class ChromeBrowserFieldTrials : public variations::Pl
       const variations::EntropyProviders& entropy_providers,
       base::FeatureList* feature_list) override;
   void RegisterSyntheticTrials() override;
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   void RegisterFeatureOverrides(base::FeatureList* feature_list) override;
 #endif
 
