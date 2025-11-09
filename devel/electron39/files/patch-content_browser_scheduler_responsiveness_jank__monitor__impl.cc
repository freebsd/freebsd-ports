--- content/browser/scheduler/responsiveness/jank_monitor_impl.cc.orig	2025-03-24 20:50:14 UTC
+++ content/browser/scheduler/responsiveness/jank_monitor_impl.cc
@@ -337,7 +337,7 @@ void JankMonitorImpl::ThreadExecutionState::DidRunTask
     // in context menus, among others). Simply ignore the mismatches for now.
     // See https://crbug.com/929813 for the details of why the mismatch
     // happens.
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE)
     task_execution_metadata_.clear();
 #endif
     return;
