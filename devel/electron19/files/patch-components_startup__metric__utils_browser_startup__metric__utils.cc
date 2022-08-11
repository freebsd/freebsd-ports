--- components/startup_metric_utils/browser/startup_metric_utils.cc.orig	2022-05-25 04:00:59 UTC
+++ components/startup_metric_utils/browser/startup_metric_utils.cc
@@ -308,7 +308,7 @@ base::TimeTicks StartupTimeToTimeTicks(base::Time time
 
 // Enabling this logic on OS X causes a significant performance regression.
 // https://crbug.com/601270
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   static bool statics_initialized = false;
 
   base::ThreadPriority previous_priority = base::ThreadPriority::NORMAL;
@@ -322,7 +322,7 @@ base::TimeTicks StartupTimeToTimeTicks(base::Time time
   static const base::Time time_base = base::Time::Now();
   static const base::TimeTicks trace_ticks_base = base::TimeTicks::Now();
 
-#if !BUILDFLAG(IS_APPLE)
+#if !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_BSD)
   if (!statics_initialized) {
     base::PlatformThread::SetCurrentThreadPriority(previous_priority);
   }
