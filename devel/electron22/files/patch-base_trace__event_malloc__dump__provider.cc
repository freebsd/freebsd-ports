--- base/trace_event/malloc_dump_provider.cc.orig	2022-10-24 13:33:33 UTC
+++ base/trace_event/malloc_dump_provider.cc
@@ -24,6 +24,8 @@
 
 #if BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
+#elif defined(OS_BSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -186,7 +188,7 @@ void ReportAppleAllocStats(size_t* total_virtual_size,
 
 #if (BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) && BUILDFLAG(IS_ANDROID)) || \
     (!BUILDFLAG(USE_PARTITION_ALLOC_AS_MALLOC) && !BUILDFLAG(IS_WIN) &&    \
-     !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_FUCHSIA))
+     !BUILDFLAG(IS_APPLE) && !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_BSD))
 void ReportMallinfoStats(ProcessMemoryDump* pmd,
                          size_t* total_virtual_size,
                          size_t* resident_size,
@@ -357,6 +359,9 @@ bool MallocDumpProvider::OnMemoryDump(const MemoryDump
                      &allocated_objects_count);
 #elif BUILDFLAG(IS_FUCHSIA)
 // TODO(fuchsia): Port, see https://crbug.com/706592.
+#elif defined(OS_BSD)
+  total_virtual_size = 0;
+  allocated_objects_size = 0;
 #else
   ReportMallinfoStats(/*pmd=*/nullptr, &total_virtual_size, &resident_size,
                       &allocated_objects_size, &allocated_objects_count);
