--- ./assembler/wtf/Platform.h.orig	2016-09-07 UTC
+++ ./assembler/wtf/Platform.h
@@ -213,6 +213,7 @@
 #elif defined(__ARM_ARCH_6__) \
    || defined(__ARM_ARCH_6J__) \
    || defined(__ARM_ARCH_6K__) \
+   || defined(__ARM_ARCH_6KZ__) \
    || defined(__ARM_ARCH_6Z__) \
    || defined(__ARM_ARCH_6ZK__) \
    || defined(__ARM_ARCH_6T2__) \
@@ -243,6 +244,7 @@
 
 #elif defined(__ARM_ARCH_6J__) \
    || defined(__ARM_ARCH_6K__) \
+   || defined(__ARM_ARCH_6KZ__) \
    || defined(__ARM_ARCH_6Z__) \
    || defined(__ARM_ARCH_6ZK__) \
    || defined(__ARM_ARCH_6M__)
