--- base/allocator/partition_allocator/partition_address_space.cc.orig	2023-08-10 01:48:30 UTC
+++ base/allocator/partition_allocator/partition_address_space.cc
@@ -420,7 +420,7 @@ void PartitionAddressSpace::UninitThreadIsolatedPoolFo
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
 
 PageCharacteristics page_characteristics;
 
