--- chrome/browser/background/background_mode_optimizer.cc.orig	2023-05-25 00:41:42 UTC
+++ chrome/browser/background/background_mode_optimizer.cc
@@ -31,7 +31,7 @@ std::unique_ptr<BackgroundModeOptimizer> BackgroundMod
     return nullptr;
   }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (base::FeatureList::IsEnabled(features::kBackgroundModeAllowRestart)) {
     return base::WrapUnique(new BackgroundModeOptimizer());
   }
