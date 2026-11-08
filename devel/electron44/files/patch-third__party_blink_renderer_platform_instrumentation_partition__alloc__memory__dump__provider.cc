--- third_party/blink/renderer/platform/instrumentation/partition_alloc_memory_dump_provider.cc.orig	2025-08-26 20:49:50 UTC
+++ third_party/blink/renderer/platform/instrumentation/partition_alloc_memory_dump_provider.cc
@@ -14,7 +14,9 @@ namespace blink {
 
 namespace blink {
 
+#if !BUILDFLAG(IS_BSD)
 const char kPartitionAllocDumpName[] = "partition_alloc";
+#endif
 
 PartitionAllocMemoryDumpProvider* PartitionAllocMemoryDumpProvider::Instance() {
   DEFINE_STATIC_LOCAL(PartitionAllocMemoryDumpProvider, instance, ());
@@ -24,6 +26,7 @@ bool PartitionAllocMemoryDumpProvider::OnMemoryDump(
 bool PartitionAllocMemoryDumpProvider::OnMemoryDump(
     const base::trace_event::MemoryDumpArgs& args,
     base::trace_event::ProcessMemoryDump* memory_dump) {
+#if !BUILDFLAG(IS_BSD)
   using base::trace_event::MemoryDumpLevelOfDetail;
 
   MemoryDumpLevelOfDetail level_of_detail = args.level_of_detail;
@@ -48,6 +51,7 @@ bool PartitionAllocMemoryDumpProvider::OnMemoryDump(
       "size", "bytes", partition_stats_dumper.total_active_bytes());
   memory_dump->AddOwnershipEdge(allocated_objects_dump->guid(),
                                 partitions_dump->guid());
+#endif
 
   return true;
 }
