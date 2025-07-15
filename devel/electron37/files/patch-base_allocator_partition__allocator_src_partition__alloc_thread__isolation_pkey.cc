--- base/allocator/partition_allocator/src/partition_alloc/thread_isolation/pkey.cc.orig	2024-08-14 20:54:22 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/thread_isolation/pkey.cc
@@ -16,7 +16,7 @@
 #include "partition_alloc/partition_alloc_check.h"
 #include "partition_alloc/thread_isolation/thread_isolation.h"
 
-#if !PA_BUILDFLAG(IS_LINUX) && !PA_BUILDFLAG(IS_CHROMEOS)
+#if !PA_BUILDFLAG(IS_LINUX) && !PA_BUILDFLAG(IS_CHROMEOS) && !PA_BUILDFLAG(IS_BSD)
 #error "This pkey code is currently only supported on Linux and ChromeOS"
 #endif
 
