This byte-order check is incorrect as <sys/_endian.h> unconditionally defines
_BIG_ENDIAN, regardless of whether we are on a big or little endian target.

https://github.com/DLTcollab/sse2neon/issues/752

--- sse2neon.h.orig	2025-12-27 17:45:58 UTC
+++ sse2neon.h
@@ -349,7 +349,7 @@
 #if defined(__BYTE_ORDER__) && (__BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__)
 #error "sse2neon requires little-endian target; big-endian is not supported"
 #elif defined(__ARMEB__) || defined(__AARCH64EB__) || \
-    defined(__BIG_ENDIAN__) || defined(_BIG_ENDIAN)
+    defined(__BIG_ENDIAN__)
 #error "sse2neon requires little-endian target; big-endian is not supported"
 #endif
 
