--- chrome/browser/metrics/process_memory_metrics_emitter.cc.orig	2019-09-10 11:13:40 UTC
+++ chrome/browser/metrics/process_memory_metrics_emitter.cc
@@ -360,7 +360,7 @@ void EmitProcessUmaAndUkm(const GlobalMemoryDump::Proc
 
   builder->SetPrivateMemoryFootprint(pmd.os_dump().private_footprint_kb / 1024);
   builder->SetSharedMemoryFootprint(pmd.os_dump().shared_footprint_kb / 1024);
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   builder->SetPrivateSwapFootprint(pmd.os_dump().private_footprint_swap_kb /
                                    1024);
 #endif
@@ -383,7 +383,7 @@ void EmitProcessUmaAndUkm(const GlobalMemoryDump::Proc
   MEMORY_METRICS_HISTOGRAM_MB(
       std::string(UMA_PREFIX) + process_name + ".SharedMemoryFootprint",
       pmd.os_dump().shared_footprint_kb / 1024);
-#if defined(OS_LINUX) || defined(OS_ANDROID)
+#if defined(OS_LINUX) || defined(OS_ANDROID) || defined(OS_BSD)
   MEMORY_METRICS_HISTOGRAM_MB(
       std::string(UMA_PREFIX) + process_name + ".PrivateSwapFootprint",
       pmd.os_dump().private_footprint_swap_kb / 1024);
