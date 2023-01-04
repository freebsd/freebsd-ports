--- src/luajit2/src/lj_arch.h.orig	2023-01-04 21:49:40 UTC
+++ src/luajit2/src/lj_arch.h
@@ -291,8 +291,14 @@
 #error "Need at least GCC 4.2 or newer"
 #endif
 #elif !LJ_TARGET_PS3
+#if __clang__
+#if ((__clang_major__ < 3) || ((__clang_major__ == 3) && __clang_minor__ < 5))
+#error "Need at least Clang 3.5 or newer"
+#endif
+#else
 #if (__GNUC__ < 4) || ((__GNUC__ == 4) && __GNUC_MINOR__ < 3)
 #error "Need at least GCC 4.3 or newer"
+#endif
 #endif
 #endif
 #endif
