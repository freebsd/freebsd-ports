--- src/base/cpu_stats.cc.orig	2026-10-16 12:33:33 UTC
+++ src/base/cpu_stats.cc
@@ -116,13 +116,13 @@ float CPUStats::GetSystemCPULoad() {
 
 #endif  // __APPLE__
 
-#if defined(__linux__) || defined(__wasm__)
+#if defined(__linux__) || defined(__wasm__) || defined(__FreeBSD__)
   // NOT IMPLEMENTED
   // TODO(taku): implement Linux version
   // can take the info from /proc/stats
   const uint64_t total_times = 0;
   const uint64_t cpu_times = 0;
-#endif  // __linux__ || __wasm__
+#endif  // __linux__ || __wasm__ || __FreeBSD__
 
   return UpdateCPULoad(total_times, cpu_times, &prev_system_total_times_,
                        &prev_system_cpu_times_);
@@ -169,11 +169,11 @@ float CPUStats::GetCurrentProcessCPULoad() {
                              TimeValueTToInt64(task_times_info.system_time);
 #endif  // __APPLE__
 
-#if defined(__linux__) || defined(__wasm__)
+#if defined(__linux__) || defined(__wasm__) || defined(__FreeBSD__)
   // not implemented
   const uint64_t total_times = 0;
   const uint64_t cpu_times = 0;
-#endif  // __linux__ || __wasm__
+#endif  // __linux__ || __wasm__ || __FreeBSD__
 
   return UpdateCPULoad(total_times, cpu_times,
                        &prev_current_process_total_times_,
@@ -200,9 +200,9 @@ size_t CPUStats::GetNumberOfProcessors() const {
   return static_cast<size_t>(basic_info.avail_cpus);
 #endif  // __APPLE__
 
-#if defined(__linux__) || defined(__wasm__)
+#if defined(__linux__) || defined(__wasm__) || defined(__FreeBSD__)
   // Not implemented
   return 1;
-#endif  // __linux__ || __wasm__
+#endif  // __linux__ || __wasm__ || __FreeBSD__
 }
 }  // namespace mozc
