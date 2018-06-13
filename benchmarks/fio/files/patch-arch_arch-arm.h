--- benchmarks/fio/files/patch-arch_arch-arm.h	(nonexistent)
+++ benchmarks/fio/files/patch-arch_arch-arm.h	(working copy)
@@ -0,0 +1,12 @@
+--- arch/arch-arm.h.orig	2018-05-07 14:59:32 UTC
++++ arch/arch-arm.h
+@@ -6,7 +6,8 @@
+ #if defined (__ARM_ARCH_4__) || defined (__ARM_ARCH_4T__) \
+ 	|| defined (__ARM_ARCH_5__) || defined (__ARM_ARCH_5T__) || defined (__ARM_ARCH_5E__)\
+ 	|| defined (__ARM_ARCH_5TE__) || defined (__ARM_ARCH_5TEJ__) \
+-	|| defined(__ARM_ARCH_6__)  || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__)
++	|| defined(__ARM_ARCH_6__)  || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__) \
++	|| defined(__ARM_ARCH_6KZ__)
+ #define nop             __asm__ __volatile__("mov\tr0,r0\t@ nop\n\t")
+ #define read_barrier()	__asm__ __volatile__ ("" : : : "memory")
+ #define write_barrier()	__asm__ __volatile__ ("" : : : "memory")

