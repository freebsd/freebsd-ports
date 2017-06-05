--- nanojit/njcpudetect.h.orig	2016-09-07 UTC
+++ nanojit/njcpudetect.h
@@ -77,6 +77,8 @@
 #elif   defined(__ARM_ARCH_6__) || \
         defined(__ARM_ARCH_6J__) || \
         defined(__ARM_ARCH_6T2__) || \
+        defined(__ARM_ARCH_6K__) || \
+        defined(__ARM_ARCH_6KZ__) || \
         defined(__ARM_ARCH_6Z__) || \
         defined(__ARM_ARCH_6ZK__) || \
         defined(__ARM_ARCH_6M__) || \
