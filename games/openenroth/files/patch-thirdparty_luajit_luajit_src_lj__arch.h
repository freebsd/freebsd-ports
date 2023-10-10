--- thirdparty/luajit/luajit/src/lj_arch.h.orig	2023-10-10 22:49:01 UTC
+++ thirdparty/luajit/luajit/src/lj_arch.h
@@ -463,8 +463,14 @@
 #endif
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
