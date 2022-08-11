--- base/trace_event/malloc_dump_provider.cc.orig	2022-05-19 05:17:34 UTC
+++ base/trace_event/malloc_dump_provider.cc
@@ -23,6 +23,8 @@
 
 #if BUILDFLAG(IS_APPLE)
 #include <malloc/malloc.h>
+#elif defined(OS_BSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -220,6 +222,9 @@ bool MallocDumpProvider::OnMemoryDump(const MemoryDump
                      &allocated_objects_count);
 #elif BUILDFLAG(IS_FUCHSIA)
 // TODO(fuchsia): Port, see https://crbug.com/706592.
+#elif defined(OS_BSD)
+  total_virtual_size = 0;
+  allocated_objects_size = 0;
 #else
 #if defined(__GLIBC__) && defined(__GLIBC_PREREQ)
 #if __GLIBC_PREREQ(2, 33)
