--- chrome/browser/performance_manager/policies/high_pmf_discard_policy.cc.orig	2022-05-25 04:00:48 UTC
+++ chrome/browser/performance_manager/policies/high_pmf_discard_policy.cc
@@ -16,7 +16,7 @@
 #include "content/public/browser/browser_task_traits.h"
 #include "content/public/browser/browser_thread.h"
 
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
 #include "base/memory/memory_pressure_monitor.h"
 #endif
 
@@ -121,7 +121,7 @@ void HighPMFDiscardPolicy::OnProcessMemoryMetricsAvail
 
   if (should_discard) {
     discard_attempt_in_progress_ = true;
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
     // Record the memory pressure level before discarding a tab.
     content::GetUIThreadTaskRunner({})->PostTask(
         FROM_HERE, base::BindOnce([]() {
