--- swift/stdlib/public/SwiftShims/swift/shims/SwiftStdint.h.orig	2024-06-06 04:26:30 UTC
+++ swift/stdlib/public/SwiftShims/swift/shims/SwiftStdint.h
@@ -24,7 +24,7 @@
 
 // Clang has been defining __INTxx_TYPE__ macros for a long time.
 // __UINTxx_TYPE__ are defined only since Clang 3.5.
-#if !defined(__APPLE__) && !defined(__linux__) && !defined(__OpenBSD__) && !defined(__wasi__)
+#if !defined(__APPLE__) && !defined(__linux__) && !defined(__OpenBSD__) && !defined(__FreeBSD__) && !defined(__wasi__)
 #include <stdint.h>
 typedef int64_t __swift_int64_t;
 typedef uint64_t __swift_uint64_t;
