--- base/allocator/partition_allocator/partition_address_space.cc.orig	2022-11-30 08:12:58 UTC
+++ base/allocator/partition_allocator/partition_address_space.cc
@@ -294,7 +294,7 @@ void PartitionAddressSpace::UninitConfigurablePoolForT
   setup_.configurable_pool_base_mask_ = 0;
 }
 
-#if BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
 
 PageCharacteristics page_characteristics;
 
