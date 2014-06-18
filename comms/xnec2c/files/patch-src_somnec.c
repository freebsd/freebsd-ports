--- src/somnec.c.orig	2013-12-01 23:01:31.000000000 -0800
+++ src/somnec.c	2014-06-08 17:51:47.000000000 -0700
@@ -38,6 +38,9 @@
 #include "somnec.h"
 #include "shared.h"
 
+#include "clog.c"
+#include "cexp.c"
+
 /* common /evlcom/ */
 static int jh;
 static double ck2, ck2sq, tkmag, tsmag, ck1r, zph, rho;
