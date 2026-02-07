--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/debug/proc_maps_linux.cc.orig	2025-08-26 20:49:50 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/debug/proc_maps_linux.cc
@@ -19,7 +19,7 @@
 #include "partition_alloc/partition_alloc_check.h"
 
 #if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || \
-    PA_BUILDFLAG(IS_ANDROID)
+    PA_BUILDFLAG(IS_ANDROID) || PA_BUILDFLAG(IS_BSD)
 #include <inttypes.h>
 #endif
 
