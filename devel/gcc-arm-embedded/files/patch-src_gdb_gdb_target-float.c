--- src/gdb/gdb/target-float.c.orig	2019-10-26 00:03:38 UTC
+++ src/gdb/gdb/target-float.c
@@ -1153,7 +1153,9 @@ host_float_ops<T>::compare (const gdb_byte *x, const s
 
 #ifdef HAVE_LIBMPFR
 
+#ifndef MPFR_USE_INTMAX_T
 #define MPFR_USE_INTMAX_T
+#endif
 
 #include <mpfr.h>
 
