--- liboil/simdpack/sincos_f64.c.orig	Sun Oct  9 09:59:12 2005
+++ liboil/simdpack/sincos_f64.c	Sun Oct  9 10:01:03 2005
@@ -71,6 +71,7 @@
 }
 OIL_DEFINE_IMPL (sincos_f64_i20_fast, sincos_f64);
 
+/*
 #ifdef _GNU_SOURCE
 static void
 sincos_f64_sincos (double *dest_sin, double *dest_cos, int n, double *offset,
@@ -83,5 +84,6 @@
 	}
 }
 OIL_DEFINE_IMPL (sincos_f64_sincos, sincos_f64);
 #endif
+*/
 
