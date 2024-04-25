--- src/core/macros.h.orig	2024-03-14 20:05:43 UTC
+++ src/core/macros.h
@@ -45,6 +45,10 @@ char (&COUNTOF_Helper(T (&array)[N]))[N];
 #include <malloc.h>
 #define stackalloc(T, n) reinterpret_cast<T *>(_alloca(sizeof(T) * n))
 #else
+#ifdef __FreeBSD__
+#include <stdlib.h>
+#else
 #include <alloca.h>
+#endif
 #define stackalloc(T, n) reinterpret_cast<T *>(alloca(sizeof(T) * n))
 #endif
