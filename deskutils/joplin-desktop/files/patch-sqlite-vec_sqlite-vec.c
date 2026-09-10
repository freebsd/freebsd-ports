--- sqlite-vec/sqlite-vec.c.orig	2026-09-07 08:18:36 UTC
+++ sqlite-vec/sqlite-vec.c
@@ -61,7 +61,7 @@ SQLITE_EXTENSION_INIT1
 #define LONGDOUBLE_TYPE long double
 #endif
 
-#ifndef _WIN32
+/*#ifndef _WIN32
 #ifndef __EMSCRIPTEN__
 #ifndef __COSMOPOLITAN__
 #ifndef __wasi__
@@ -71,7 +71,7 @@ typedef u_int64_t uint64_t;
 #endif
 #endif
 #endif
-#endif
+#endif*/
 
 typedef int8_t i8;
 typedef uint8_t u8;
