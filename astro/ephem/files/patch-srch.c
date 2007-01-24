--- srch.c.orig	Sun Jan 21 21:10:29 2007
+++ srch.c	Sun Jan 21 21:11:37 2007
@@ -6,9 +6,14 @@
 
 #include <stdio.h>
 #include <math.h>
+#include <string.h>
 #include "screen.h"
 
-extern char *strcpy();
+static set_function();
+static set_accuracy();
+static srch_minmax(double mjd, double v, double *tmincp);
+static srch_solve0(double mjd, double v, double *tmincp);
+static srch_binary(double mjd, double v, double *tmincp);
 
 static int (*srch_f)();
 static int srch_tmscalled;
