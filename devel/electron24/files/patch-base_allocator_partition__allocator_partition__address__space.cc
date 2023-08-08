--- base/allocator/partition_allocator/partition_address_space.cc.orig	2023-03-30 00:33:38 UTC
+++ base/allocator/partition_allocator/partition_address_space.cc
@@ -417,7 +417,7 @@ void PartitionAddressSpace::UninitPkeyPoolForTesting()
 }
 #endif
 
-#if BUILDFLAG(IS_LINUX) && defined(ARCH_CPU_ARM64)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && defined(ARCH_CPU_ARM64)
 
 PageCharacteristics page_characteristics;
 
