--- base/allocator/partition_allocator/page_allocator_internals_posix.h.orig	2020-05-26 07:48:14 UTC
+++ base/allocator/partition_allocator/page_allocator_internals_posix.h
@@ -22,7 +22,7 @@
 #if defined(OS_ANDROID)
 #include <sys/prctl.h>
 #endif
-#if defined(OS_LINUX)
+#if defined(OS_BSD) || defined(OS_LINUX)
 #include <sys/resource.h>
 
 #include <algorithm>
