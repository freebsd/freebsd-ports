--- chrome/browser/background/background_mode_optimizer.cc.orig	2021-01-07 00:36:21 UTC
+++ chrome/browser/background/background_mode_optimizer.cc
@@ -30,10 +30,10 @@ std::unique_ptr<BackgroundModeOptimizer> BackgroundMod
           switches::kKeepAliveForTest))
     return nullptr;
 
-#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(features::kBackgroundModeAllowRestart))
     return base::WrapUnique(new BackgroundModeOptimizer());
-#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
   return nullptr;
 }
