--- chrome/browser/task_manager/sampling/task_group_sampler.cc.orig	2025-03-24 20:50:14 UTC
+++ chrome/browser/task_manager/sampling/task_group_sampler.cc
@@ -45,7 +45,7 @@ TaskGroupSampler::TaskGroupSampler(
     const OnCpuRefreshCallback& on_cpu_refresh,
     const OnSwappedMemRefreshCallback& on_swapped_mem_refresh,
     const OnIdleWakeupsCallback& on_idle_wakeups,
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
     const OnOpenFdCountCallback& on_open_fd_count,
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
     const OnProcessPriorityCallback& on_process_priority)
@@ -55,7 +55,7 @@ TaskGroupSampler::TaskGroupSampler(
       on_cpu_refresh_callback_(on_cpu_refresh),
       on_swapped_mem_refresh_callback_(on_swapped_mem_refresh),
       on_idle_wakeups_callback_(on_idle_wakeups),
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
       on_open_fd_count_callback_(on_open_fd_count),
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
       on_process_priority_callback_(on_process_priority) {
@@ -85,7 +85,7 @@ void TaskGroupSampler::Refresh(int64_t refresh_flags) 
         base::BindOnce(on_swapped_mem_refresh_callback_));
   }
 
-#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   if (TaskManagerObserver::IsResourceRefreshEnabled(REFRESH_TYPE_IDLE_WAKEUPS,
                                                     refresh_flags)) {
     blocking_pool_runner_->PostTaskAndReplyWithResult(
@@ -95,7 +95,7 @@ void TaskGroupSampler::Refresh(int64_t refresh_flags) 
   }
 #endif  // BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
   if (TaskManagerObserver::IsResourceRefreshEnabled(REFRESH_TYPE_FD_COUNT,
                                                     refresh_flags)) {
     blocking_pool_runner_->PostTaskAndReplyWithResult(
@@ -152,7 +152,7 @@ int TaskGroupSampler::RefreshIdleWakeupsPerSecond() {
   return process_metrics_->GetIdleWakeupsPerSecond();
 }
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_BSD)
 int TaskGroupSampler::RefreshOpenFdCount() {
   DCHECK_CALLED_ON_VALID_SEQUENCE(worker_pool_sequenced_checker_);
 
