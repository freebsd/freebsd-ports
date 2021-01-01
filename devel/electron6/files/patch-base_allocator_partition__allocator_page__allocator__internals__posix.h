--- base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2019-09-10 11:13:31 UTC
+++ base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -16,7 +16,7 @@
 
 #include <mach/mach.h>
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_BSD) || defined(OS_LINUX)
 #include <sys/resource.h>
 
 #include <algorithm>
