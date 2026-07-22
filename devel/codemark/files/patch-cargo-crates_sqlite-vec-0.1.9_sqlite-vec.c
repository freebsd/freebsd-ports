Define the fixed-width integer types from <stdint.h> on FreeBSD, which
does not provide the historical BSD u_int8_t/u_int16_t/u_int64_t names
the upstream fallback typedefs rely on.

--- cargo-crates/sqlite-vec-0.1.9/sqlite-vec.c.orig	2024-11-21 00:00:00 UTC
+++ cargo-crates/sqlite-vec-0.1.9/sqlite-vec.c
@@ -64,10 +64,12 @@
 #ifndef _WIN32
 #ifndef __EMSCRIPTEN__
 #ifndef __COSMOPOLITAN__
 #ifndef __wasi__
+#ifndef __FreeBSD__
 typedef u_int8_t uint8_t;
 typedef u_int16_t uint16_t;
 typedef u_int64_t uint64_t;
+#endif
 #endif
 #endif
 #endif
