--- base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.cc.orig	2025-08-26 20:49:50 UTC
+++ base/allocator/partition_allocator/src/partition_alloc/page_allocator_internals_posix.cc
@@ -44,7 +44,7 @@ uint32_t SecTaskGetCodeSignStatus(SecTaskRef task) API
 
 #if PA_BUILDFLAG(HAS_MEMORY_TAGGING) ||                                        \
     (defined(__ARM_FEATURE_BTI_DEFAULT) && (__ARM_FEATURE_BTI_DEFAULT == 1) && \
-     __has_include(<sys/ifunc.h>))
+     __has_include(<sys/ifunc.h>) && !PA_BUILDFLAG(IS_BSD))
 struct __ifunc_arg_t;
 
 #include "partition_alloc/aarch64_support.h"
