--- moonnf.c.orig	Sun Jan 21 20:53:58 2007
+++ moonnf.c	Sun Jan 21 20:54:21 2007
@@ -2,6 +2,8 @@
 #include <math.h>
 #include "astro.h"
 
+static m(double t, double k, double *mjd);
+
 #define	unw(w,z)	((w)-floor((w)/(z))*(z))
 
 /* given a modified Julian date, mjd, return the mjd of the new
