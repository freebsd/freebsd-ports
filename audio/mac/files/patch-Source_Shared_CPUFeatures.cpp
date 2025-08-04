--- Source/Shared/CPUFeatures.cpp.orig	2025-08-04 20:52:19 UTC
+++ Source/Shared/CPUFeatures.cpp
@@ -4,7 +4,7 @@
 #if defined(PLATFORM_LINUX)
     #include <sys/auxv.h>
 
-    #if defined(__arm__)
+    #if defined(__arm__) && defined(__linux__)
         #include <asm/hwcap.h>
 
         #ifndef HWCAP_NEON
@@ -187,7 +187,14 @@ bool GetNeonSupported()
 #if defined(__ARM_NEON) || defined(__ARM_NEON__) || defined(__aarch64__) || defined(_M_ARM64) || defined(_M_ARM64EC)
     return true;
 #elif defined(__arm__) && defined(PLATFORM_LINUX)
+#ifdef __linux__
     return getauxval(AT_HWCAP) & HWCAP_NEON;
+#elif defined(__FreeBSD__)
+    long hwcap = 0;
+
+    elf_aux_info(AT_HWCAP, &hwcap, sizeof hwcap);
+    return (hwcap & HWCAP_NEON);
+#endif
 #else
     return false;
 #endif
