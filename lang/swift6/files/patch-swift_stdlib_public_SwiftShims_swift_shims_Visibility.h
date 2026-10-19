--- swift/stdlib/public/SwiftShims/swift/shims/Visibility.h.orig	2026-10-10 18:48:34 UTC
+++ swift/stdlib/public/SwiftShims/swift/shims/Visibility.h
@@ -110,8 +110,10 @@
 #endif
 
 // WASM says yes to __has_attribute(musttail) but doesn't support using it, so
-// exclude WASM from SWIFT_MUSTTAIL.
-#if __has_attribute(musttail) && !defined(__wasm__)
+// exclude WASM from SWIFT_MUSTTAIL.  PowerPC also reports support, but LLVM
+// cannot emit guaranteed tail calls for indirect calls there and clang
+// rejects them with a hard error, so exclude PowerPC as well.
+#if __has_attribute(musttail) && !defined(__wasm__) && !defined(__powerpc__)
 #define SWIFT_MUSTTAIL [[clang::musttail]]
 #else
 #define SWIFT_MUSTTAIL
