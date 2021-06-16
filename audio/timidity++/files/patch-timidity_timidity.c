--- timidity/timidity.c.orig	2018-08-28 23:33:39 UTC
+++ timidity/timidity.c
@@ -5393,7 +5393,8 @@ MAIN_INTERFACE void timidity_start_initialize(void)
     fp_except fpexp;
 #endif
 
-#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
+#if defined(FP_X_INV) && defined(FP_X_DZ) && \
+  (defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__))
     fpexp = fpgetmask();
     fpsetmask(fpexp & ~(FP_X_INV|FP_X_DZ));
 #endif
