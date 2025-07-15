--- components/performance_manager/decorators/process_metrics_decorator.cc.orig	2025-01-27 17:37:37 UTC
+++ components/performance_manager/decorators/process_metrics_decorator.cc
@@ -264,7 +264,7 @@ void ProcessMetricsDecorator::DidGetMemoryUsage(
     // RSS and PMF to each node proportionally to its V8 heap size.
     uint64_t process_rss = process_dump_iter.os_dump().resident_set_kb;
     process_node->set_resident_set_kb(process_rss);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     process_node->set_private_swap_kb(
         process_dump_iter.os_dump().private_footprint_swap_kb);
 #endif
