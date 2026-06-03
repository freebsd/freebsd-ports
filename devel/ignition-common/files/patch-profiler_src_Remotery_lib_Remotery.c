-- Avoid redefining rsize_t on FreeBSD in Remotery.
-- FreeBSD's stdlib.h already defines rsize_t behind _RSIZE_T_DEFINED, and
-- this duplicate typedef breaks ignition-common with clang 19.
-- Upstream reference: https://github.com/Celtoys/Remotery
--- profiler/src/Remotery/lib/Remotery.c.orig	2026-05-17 00:56:58 UTC
+++ profiler/src/Remotery/lib/Remotery.c
@@ -1170,7 +1170,8 @@ typedef int errno_t;
 #endif
 
-#if (!defined(_WIN64) && !defined(__APPLE__)) || (defined(__MINGW32__) && !(defined(RSIZE_T_DEFINED) || defined(_RSIZE_T_DEFINED)))
+#if (!defined(_WIN64) && !defined(__APPLE__) && !defined(_RSIZE_T_DEFINED)) || \
+  (defined(__MINGW32__) && !(defined(RSIZE_T_DEFINED) || defined(_RSIZE_T_DEFINED)))
 typedef unsigned int rsize_t;
 #endif
 
