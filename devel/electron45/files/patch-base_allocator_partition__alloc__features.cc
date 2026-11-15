--- base/allocator/partition_alloc_features.cc.orig	2026-10-19 21:50:55 UTC
+++ base/allocator/partition_alloc_features.cc
@@ -132,7 +132,7 @@ constinit const FeatureParam<std::string>
     kPartitionAllocSchedulerLoopQuarantineConfig{
         &kPartitionAllocSchedulerLoopQuarantine,
         "PartitionAllocSchedulerLoopQuarantineConfig",
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
         R"({
           "browser":{
             "main":{
