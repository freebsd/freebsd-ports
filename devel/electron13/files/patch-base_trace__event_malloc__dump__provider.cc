--- base/trace_event/malloc_dump_provider.cc.orig	2021-07-15 19:13:30 UTC
+++ base/trace_event/malloc_dump_provider.cc
@@ -20,6 +20,8 @@
 
 #if defined(OS_APPLE)
 #include <malloc/malloc.h>
+#elif defined(OS_BSD)
+#include <stdlib.h>
 #else
 #include <malloc.h>
 #endif
@@ -199,6 +201,9 @@ bool MallocDumpProvider::OnMemoryDump(const MemoryDump
   }
 #elif defined(OS_FUCHSIA)
 // TODO(fuchsia): Port, see https://crbug.com/706592.
+#elif defined(OS_BSD)
+  total_virtual_size = 0;
+  allocated_objects_size = 0;
 #else
   struct mallinfo info = mallinfo();
   // In case of Android's jemalloc |arena| is 0 and the outer pages size is
