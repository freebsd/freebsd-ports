--- base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/debug/proc_maps_linux.cc.orig	2025-06-30 07:04:30 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/partition_alloc_base/debug/proc_maps_linux.cc
@@ -15,7 +15,7 @@
 #include "partition_alloc/partition_alloc_check.h"
 
 #if PA_BUILDFLAG(IS_LINUX) || PA_BUILDFLAG(IS_CHROMEOS) || \
-    PA_BUILDFLAG(IS_ANDROID)
+    PA_BUILDFLAG(IS_ANDROID) || PA_BUILDFLAG(IS_BSD)
 #include <inttypes.h>
 #endif
 
