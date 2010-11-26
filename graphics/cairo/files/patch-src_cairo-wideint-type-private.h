--- src/cairo-wideint-type-private.h.orig	2010-11-26 02:41:47.000000000 -0500
+++ src/cairo-wideint-type-private.h	2010-11-26 02:42:07.000000000 -0500
@@ -121,6 +121,11 @@ typedef struct _cairo_quorem64 {
     cairo_int64_t	rem;
 } cairo_quorem64_t;
 
+/* Intrinsic __uint128_t support is broken on gcc 3.4/sparc. */
+#if __GNUC__ == 3 && __GNUC_MINOR__ == 4
+#undef HAVE___UINT128_T
+#endif
+
 /* gcc has a non-standard name. */
 #if HAVE___UINT128_T && !HAVE_UINT128_T
 typedef __uint128_t uint128_t;
