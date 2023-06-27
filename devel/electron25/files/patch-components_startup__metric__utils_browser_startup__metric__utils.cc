--- components/startup_metric_utils/browser/startup_metric_utils.cc.orig	2022-08-31 12:19:35 UTC
+++ components/startup_metric_utils/browser/startup_metric_utils.cc
@@ -311,7 +311,7 @@ base::TimeTicks StartupTimeToTimeTicks(base::Time time
 // Enabling this logic on OS X causes a significant performance regression.
 // TODO(crbug.com/601270): Remove IS_APPLE ifdef once priority changes are
 // ignored on Mac main thread.
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   static bool statics_initialized = false;
   if (!statics_initialized) {
     statics_initialized = true;
