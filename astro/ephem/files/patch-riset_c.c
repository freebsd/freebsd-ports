--- riset_c.c.orig	Sun Jan 21 21:07:04 2007
+++ riset_c.c	Sun Jan 21 21:08:51 2007
@@ -6,6 +6,16 @@
 #include "circum.h"
 #include "screen.h"	/* just for SUN and MOON */
 
+static iterative_riset(int p, Now *np, int hzn,
+		       double *ltr, double *lts, double *ltt,
+		       double *azr, double *azs, double *altt,
+		       int *status);
+static stationary_riset(int p, double mjd0, Now *np, int hzn,
+			double *lstr, double *lsts, double *lstt,
+			double *azr, double *azs, double *altt,
+			int *status);
+static transit(double r, double d, Now *np, double *lstt, double *altt);
+
 #define	TRACE(x)	{FILE *fp = fopen("trace","a"); fprintf x; fclose(fp);}
 
 #define	STDREF	degrad(34./60.)	/* nominal horizon refraction amount */
