--- assembler/wtf/Platform.h.orig	2016-12-23 16:20:31 UTC
+++ assembler/wtf/Platform.h
@@ -269,6 +269,7 @@
 #elif defined(__ARM_ARCH_6__) \
     || defined(__ARM_ARCH_6J__) \
     || defined(__ARM_ARCH_6K__) \
+    || defined(__ARM_ARCH_6KZ__) \
     || defined(__ARM_ARCH_6Z__) \
     || defined(__ARM_ARCH_6ZK__) \
     || defined(__ARM_ARCH_6T2__) \
@@ -306,6 +307,7 @@
 
 #elif defined(__ARM_ARCH_6J__) \
     || defined(__ARM_ARCH_6K__) \
+    || defined(__ARM_ARCH_6KZ__) \
     || defined(__ARM_ARCH_6Z__) \
     || defined(__ARM_ARCH_6ZK__) \
     || defined(__ARM_ARCH_6M__)
