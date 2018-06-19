On armv6 platform:
./wtf/Platform.h:323:6: error: "Not supported ARM architecture"
#    error "Not supported ARM architecture"
     ^

Obtained from: www/webkit-gtk3/files/patch-Source_WTF_wtf_Platform.h

This patch reportedly fixes build for ARM. See PR 208569

--- src/qt/qtwebkit/Source/WTF/wtf/Platform.h.orig	2018-06-14 11:03:55 UTC
+++ src/qt/qtwebkit/Source/WTF/wtf/Platform.h
@@ -232,6 +232,7 @@
 #elif defined(__ARM_ARCH_6__) \
     || defined(__ARM_ARCH_6J__) \
     || defined(__ARM_ARCH_6K__) \
+    || defined(__ARM_ARCH_6KZ__) \
     || defined(__ARM_ARCH_6Z__) \
     || defined(__ARM_ARCH_6ZK__) \
     || defined(__ARM_ARCH_6T2__) \
