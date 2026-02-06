--- lib/bpf/src/str_error.c.orig	2025-10-27 20:52:10 UTC
+++ lib/bpf/src/str_error.c
@@ -8,6 +8,15 @@
 #ifndef ENOTSUPP
 #define ENOTSUPP	524
 #endif
+#ifndef EBADFD
+#define EBADFD 8816
+#endif
+#ifndef ENODATA
+#define ENODATA 8817
+#endif
+#ifndef EUCLEAN
+#define EUCLEAN 8818
+#endif
 
 /* make sure libbpf doesn't use kernel-only integer typedefs */
 #pragma GCC poison u8 u16 u32 u64 s8 s16 s32 s64
