--- src/common/darktable.h.orig	2024-07-17 15:29:39 UTC
+++ src/common/darktable.h
@@ -153,7 +153,7 @@ extern "C" {
 #if __has_attribute(target_clones) && !defined(_WIN32) && !defined(NATIVE_ARCH) && !defined(__APPLE__)
 # if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64)
 #define __DT_CLONE_TARGETS__ __attribute__((target_clones("default", "sse2", "sse3", "sse4.1", "sse4.2", "popcnt", "avx", "avx2", "avx512f", "fma4")))
-# elif defined(__PPC64__)
+# elif defined(__PPC64__) && defined(__GLIBC__)
 /* __PPC64__ is the only macro tested for in is_supported_platform.h, other macros would fail there anyway. */
 #define __DT_CLONE_TARGETS__ __attribute__((target_clones("default","cpu=power9")))
 # else
