--- src/atomic_ops/sysdeps/gcc/arm.h.orig	2016-03-12 13:41:24 UTC
+++ src/atomic_ops/sysdeps/gcc/arm.h
@@ -58,7 +58,8 @@
 # if !defined(__ARM_ARCH_6__) && !defined(__ARM_ARCH_6J__) \
      && !defined(__ARM_ARCH_6T2__) && !defined(__ARM_ARCH_6Z__) \
      && !defined(__ARM_ARCH_6ZT2__)
-#   if !defined(__ARM_ARCH_6K__) && !defined(__ARM_ARCH_6ZK__)
+#   if !defined(__ARM_ARCH_6K__) && !defined(__ARM_ARCH_6KZ__) \
+     && !defined(__ARM_ARCH_6ZK__)
       /* DMB is present in ARMv6M and ARMv7+.   */
 #     define AO_ARM_HAVE_DMB
 #   endif
