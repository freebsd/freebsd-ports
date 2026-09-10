--- base/allocator/partition_allocator/src/partition_alloc/thread_isolation/pkey.cc.orig	2026-06-23 23:37:18 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/thread_isolation/pkey.cc
@@ -17,7 +17,7 @@
 #include "partition_alloc/partition_alloc_check.h"
 #include "partition_alloc/thread_isolation/thread_isolation.h"
 
-#if !PA_BUILDFLAG(IS_LINUX) && !PA_BUILDFLAG(IS_CHROMEOS)
+#if !PA_BUILDFLAG(IS_LINUX) && !PA_BUILDFLAG(IS_CHROMEOS) && !PA_BUILDFLAG(IS_BSD)
 #error "This pkey code is currently only supported on Linux and ChromeOS"
 #endif
 
