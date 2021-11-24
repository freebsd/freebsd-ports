--- components/startup_metric_utils/browser/startup_metric_utils.cc.orig	2021-07-15 19:13:38 UTC
+++ components/startup_metric_utils/browser/startup_metric_utils.cc
@@ -343,7 +343,7 @@ base::TimeTicks StartupTimeToTimeTicks(base::Time time
 
 // Enabling this logic on OS X causes a significant performance regression.
 // https://crbug.com/601270
-#if !defined(OS_APPLE)
+#if !defined(OS_APPLE) && !defined(OS_BSD)
   static bool statics_initialized = false;
 
   base::ThreadPriority previous_priority = base::ThreadPriority::NORMAL;
@@ -357,7 +357,7 @@ base::TimeTicks StartupTimeToTimeTicks(base::Time time
   static const base::Time time_base = base::Time::Now();
   static const base::TimeTicks trace_ticks_base = base::TimeTicks::Now();
 
-#if !defined(OS_APPLE)
+#if !defined(OS_APPLE) && !defined(OS_BSD)
   if (!statics_initialized) {
     base::PlatformThread::SetCurrentThreadPriority(previous_priority);
   }
