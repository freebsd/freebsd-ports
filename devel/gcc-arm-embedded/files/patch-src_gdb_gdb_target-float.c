--- src/gdb/gdb/target-float.c.orig	2019-01-22 18:39:51.598469000 +0300
+++ src/gdb/gdb/target-float.c	2019-01-22 18:40:20.405163000 +0300
@@ -1155,7 +1155,9 @@
 
 #ifdef HAVE_LIBMPFR
 
+#ifndef MPFR_USE_INTMAX_T
 #define MPFR_USE_INTMAX_T
+#endif
 
 #include <mpfr.h>
 
