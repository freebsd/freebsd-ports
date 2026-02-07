--- src/openzl/shared/portability.h.orig	2025-10-08 09:01:34 UTC
+++ src/openzl/shared/portability.h
@@ -211,10 +211,11 @@ ZL_BEGIN_C_DECLS
 // Detect IEEE 754 floating point support.
 // Apple doesn't define __STDC_IEC_559__, but supports IEEE 754.
 // MinGW doesn't define __STDC_IEC_559__, but supports IEEE 754.
+// FreeBSD doesn't define __STDC_IEC_559__, but supports IEEE 754.
 #if (defined(__STDC_IEC_559__) && __STDC_IEC_559__) \
         || (defined(__STDC_IEC_60559_BFP__)         \
             && __STDC_IEC_60559_BFP__ >= 202311L)   \
-        || defined(__APPLE__) || defined(__MINGW32__)
+        || defined(__APPLE__) || defined(__MINGW32__) || defined(__FreeBSD__)
 #    define ZL_HAS_IEEE_754 1
 #else
 #    define ZL_HAS_IEEE_754 0
