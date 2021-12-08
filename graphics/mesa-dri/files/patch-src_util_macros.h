--- src/util/macros.h.orig	2022-01-16 11:28:56 UTC
+++ src/util/macros.h
@@ -478,6 +478,6 @@ typedef int lock_cap_t;
 #endif
 
 /* TODO: this could be different on non-x86 architectures. */
-#define CACHE_LINE_SIZE 64
+#define MESA_CACHE_LINE_SIZE 64
 
 #endif /* UTIL_MACROS_H */
