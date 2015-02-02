--- jit/arm/Architecture-arm.cpp.orig	2013-10-29 20:40:20 UTC
+++ jit/arm/Architecture-arm.cpp
@@ -15,7 +15,7 @@
 
 // lame check for kernel version
 // see bug 586550
-#if !(defined(ANDROID) || defined(MOZ_B2G))
+#if !(defined(ANDROID) || defined(MOZ_B2G) || defined(__FreeBSD__))
 #include <asm/hwcap.h>
 #else
 #define HWCAP_VFP      (1<<0)
