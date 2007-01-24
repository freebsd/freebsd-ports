--- eq_ecl.c.orig	Sun Jan 21 20:41:41 2007
+++ eq_ecl.c	Sun Jan 21 20:42:16 2007
@@ -2,6 +2,8 @@
 #include <math.h>
 #include "astro.h"
 
+static ecleq_aux (int sw, double mjd, double x, double y, double *p, double *q);
+
 #define	EQtoECL	1
 #define	ECLtoEQ	(-1)
 
