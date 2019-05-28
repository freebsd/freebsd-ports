--- chrome/browser/background/background_mode_optimizer.cc.orig	2019-03-15 06:25:31 UTC
+++ chrome/browser/background/background_mode_optimizer.cc
@@ -30,10 +30,10 @@ std::unique_ptr<BackgroundModeOptimizer> BackgroundMod
           switches::kKeepAliveForTest))
     return nullptr;
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(features::kBackgroundModeAllowRestart))
     return base::WrapUnique(new BackgroundModeOptimizer());
-#endif  // defined(OS_WIN) || defined(OS_LINUX)
+#endif  // defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 
   return nullptr;
 }
