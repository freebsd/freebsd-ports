--- include/simdutf/portability.h.orig	2026-09-02 17:18:20 UTC
+++ include/simdutf/portability.h	2026-09-02 17:19:00 UTC
@@ -110,7 +110,7 @@
 #elif defined(__aarch64__) || defined(_M_ARM64) || defined(_M_ARM64EC)
   #define SIMDUTF_IS_ARM64 1
 #elif defined(__PPC64__) || defined(_M_PPC64)
-  #if defined(__VEC__) && defined(__ALTIVEC__)
+  #if defined(__VEC__) && defined(__ALTIVEC__) && defined(__POWER8_VECTOR__)
     #define SIMDUTF_IS_PPC64 1
   #endif
 #elif defined(__s390__)
