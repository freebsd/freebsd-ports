--- src/runtime/fopen_lfs.cpp.orig	2024-05-28 01:22:14 UTC
+++ src/runtime/fopen_lfs.cpp
@@ -3,5 +3,9 @@ extern "C" WEAK_INLINE void *halide_fopen(const char *
 extern "C" void *fopen64(const char *, const char *);
 
 extern "C" WEAK_INLINE void *halide_fopen(const char *filename, const char *type) {
+#if !defined(__FreeBSD__)
     return fopen64(filename, type);
+#else
+    return fopen(filename, type);
+#endif
 }
