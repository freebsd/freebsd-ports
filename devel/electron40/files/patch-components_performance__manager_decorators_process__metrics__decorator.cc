--- components/performance_manager/decorators/process_metrics_decorator.cc.orig	2026-01-07 00:52:53 UTC
+++ components/performance_manager/decorators/process_metrics_decorator.cc
@@ -54,7 +54,7 @@ class ProcessMetricsDecorator::NodeMetricsUpdater {
     auto* process_node = ProcessNodeImpl::FromNode(context.GetProcessNode());
     process_node->set_private_footprint(memory_summary_->private_footprint);
     process_node->set_resident_set(memory_summary_->resident_set_size);
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_BSD)
     process_node->set_private_swap(memory_summary_->private_swap);
 #endif
   }
