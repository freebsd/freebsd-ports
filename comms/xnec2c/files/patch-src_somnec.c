--- src/somnec.c.orig	2015-02-18 05:31:10 UTC
+++ src/somnec.c
@@ -38,6 +38,9 @@
 #include "somnec.h"
 #include "shared.h"
 
+#include "clog.c"
+#include "cexp.c"
+
 /* common /evlcom/ */
 static int jh;
 static double ck2, ck2sq, tkmag, tsmag, ck1r, zph, rho;
