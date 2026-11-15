--- services/tracing/public/cpp/system_metrics_sampler.cc.orig	2026-04-28 21:06:17 UTC
+++ services/tracing/public/cpp/system_metrics_sampler.cc
@@ -177,8 +177,8 @@ void SystemMetricsSampler::ProcessSampler::SampleProce
     TRACE_COUNTER(TRACE_DISABLED_BY_DEFAULT("system_metrics"),
                   "PhysicalMemoryFootprint",
                   memory_info->physical_footprint_bytes);
-#elif BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
-    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)
+#elif (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || \
+    BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_FUCHSIA)) && defined(notyet)
     TRACE_COUNTER(TRACE_DISABLED_BY_DEFAULT("system_metrics"), "VmSwapMemory",
                   memory_info->vm_swap_bytes);
     TRACE_COUNTER(TRACE_DISABLED_BY_DEFAULT("system_metrics"), "RssAnonMemory",
