--- src/openzl/shared/portability.h.orig	2026-05-17 02:41:49 UTC
+++ src/openzl/shared/portability.h
@@ -330,10 +330,11 @@ typedef __m128i __m128i_u;
 // Apple doesn't define __STDC_IEC_559__, but supports IEEE 754.
 // MinGW doesn't define __STDC_IEC_559__, but supports IEEE 754.
 // MSVC on x86/x64 supports IEEE 754.
+// FreeBSD doesn't define __STDC_IEC_559__, but supports IEEE 754.
 #if (defined(__STDC_IEC_559__) && __STDC_IEC_559__) \
         || (defined(__STDC_IEC_60559_BFP__)         \
             && __STDC_IEC_60559_BFP__ >= 202311L)   \
-        || defined(__APPLE__) || defined(__MINGW32__) || defined(_MSC_VER)
+        || defined(__APPLE__) || defined(__MINGW32__) || defined(_MSC_VER) || defined(__FreeBSD__)
 #    define ZL_HAS_IEEE_754 1
 #else
 #    define ZL_HAS_IEEE_754 0
