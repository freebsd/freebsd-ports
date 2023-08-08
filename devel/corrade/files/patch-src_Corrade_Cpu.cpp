--- src/Corrade/Cpu.cpp.orig	2023-05-22 11:59:16 UTC
+++ src/Corrade/Cpu.cpp
@@ -34,7 +34,7 @@
 /** @todo these are indented to work around acme.py extracting them to the top,
     fix properly */
 /* getauxval() for ARM on Linux and Android with API level 18+ */
-#if defined(CORRADE_TARGET_ARM) && defined(__linux__) && !(defined(CORRADE_TARGET_ANDROID) && __ANDROID_API__ < 18)
+#if defined(CORRADE_TARGET_ARM) && (defined(__linux__) && !(defined(CORRADE_TARGET_ANDROID) && __ANDROID_API__ < 18) || defined(__FreeBSD__))
     #include <sys/auxv.h>
 /* sysctlbyname() for ARM on macOS / iOS */
 #elif defined(CORRADE_TARGET_ARM) && defined(CORRADE_TARGET_APPLE)
@@ -80,7 +80,7 @@ int appleSysctlByName(const char* name) {
 }
 #endif
 
-#if defined(CORRADE_TARGET_ARM) && ((defined(__linux__) && !(defined(CORRADE_TARGET_ANDROID) && __ANDROID_API__ < 18)) || defined(CORRADE_TARGET_APPLE))
+#if defined(CORRADE_TARGET_ARM) && ((defined(__linux__) && !(defined(CORRADE_TARGET_ANDROID) && __ANDROID_API__ < 18)) || defined(CORRADE_TARGET_APPLE) || defined(__FreeBSD__))
 Features runtimeFeatures() {
     /* Use getauxval() on ARM on Linux and Android */
     #if defined(CORRADE_TARGET_ARM) && defined(__linux__) && !(defined(CORRADE_TARGET_ANDROID) && __ANDROID_API__ < 18)
@@ -130,6 +130,13 @@ Features runtimeFeatures() {
     /* No other (deinlined) implementation at the moment. The function should
        not be even defined here in that case -- it's inlined in the header
        instead, including the x86 implementation. */
+    #elif defined(CORRADE_TARGET_ARM) && defined(__FreeBSD__)
+    /* use elf_aux_info() on ARM on FreeBSD */
+    unsigned long hwcap = 0;
+
+    elf_aux_info(AT_HWCAP, &hwcap, sizeof hwcap);
+
+    return Implementation::runtimeFeatures(hwcap);
     #else
     #error
     #endif
