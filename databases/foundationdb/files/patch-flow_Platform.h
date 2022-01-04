--- flow/Platform.h.orig	2021-10-21 22:10:27 UTC
+++ flow/Platform.h
@@ -434,6 +434,12 @@ dev_t getDeviceId(std::string path);
 #include <features.h>
 #include <sys/stat.h>
 #endif
+#ifdef __freebsd__
+#ifndef __aarch64__
+#include <x86intrin.h>
+#else
+#include "sse2neon.h"
+#endif
 
 #if defined(__APPLE__)
 // Version of CLang bundled with XCode doesn't yet include ia32intrin.h.
@@ -459,7 +465,7 @@ inline static uint64_t timestampCounter() {
 #define timestampCounter() __rdtsc()
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) && !defined(__aarch64__)
 #if !(__has_builtin(__rdtsc))
 inline static uint64_t __rdtsc() {
 	uint64_t lo, hi;
