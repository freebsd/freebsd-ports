--- sse2neon.h.orig	2024-10-15 17:08:16 UTC
+++ sse2neon.h
@@ -104,7 +104,7 @@
 #pragma message("Macro name collisions may happen with unsupported compilers.")
 #endif
 
-#if defined(__GNUC__) && __GNUC__ < 10
+#if defined(__GNUC__) && !defined(__clang__) && __GNUC__ < 10
 #warning "GCC versions earlier than 10 are not supported."
 #endif
 
