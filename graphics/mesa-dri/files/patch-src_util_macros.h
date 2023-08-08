--- src/util/macros.h.orig	2022-10-11 18:53:31 UTC
+++ src/util/macros.h
@@ -448,7 +448,7 @@ typedef int lock_cap_t;
 #endif
 
 /* TODO: this could be different on non-x86 architectures. */
-#define CACHE_LINE_SIZE 64
+#define MESA_CACHE_LINE_SIZE 64
 
 #define DO_PRAGMA(X) _Pragma (#X)
 
