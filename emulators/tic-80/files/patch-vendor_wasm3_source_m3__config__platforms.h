--- vendor/wasm3/source/m3_config_platforms.h.orig	2023-08-05 12:47:20 UTC
+++ vendor/wasm3/source/m3_config_platforms.h
@@ -121,9 +121,9 @@ typedef int8_t          i8;
 # if defined (M3_COMPILER_MSVC)
 #   define vectorcall   // For MSVC, better not to specify any call convention
 # elif defined(__x86_64__)
-#   define vectorcall   __attribute__((aligned(32)))
+#   define vectorcall
 //# elif defined(__riscv) && (__riscv_xlen == 64)
-//#   define vectorcall   __attribute__((aligned(16)))
+//#   define vectorcall
 # elif defined(__MINGW32__)
 #   define vectorcall
 # elif defined(WIN32)
