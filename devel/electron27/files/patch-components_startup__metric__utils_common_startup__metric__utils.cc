--- components/startup_metric_utils/common/startup_metric_utils.cc.orig	2023-10-19 19:58:20 UTC
+++ components/startup_metric_utils/common/startup_metric_utils.cc
@@ -78,7 +78,7 @@ base::TimeTicks CommonStartupMetricRecorder::StartupTi
   // Enabling this logic on OS X causes a significant performance regression.
   // TODO(crbug.com/601270): Remove IS_APPLE ifdef once priority changes are
   // ignored on Mac main thread.
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   static bool statics_initialized = false;
   if (!statics_initialized) {
     statics_initialized = true;
