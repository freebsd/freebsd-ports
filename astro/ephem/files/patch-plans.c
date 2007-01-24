--- plans.c.orig	Sun Jan 21 21:00:06 2007
+++ plans.c	Sun Jan 21 21:04:04 2007
@@ -2,6 +2,23 @@
 #include <math.h>
 #include "astro.h"
 
+static masun(double mjd, double *mas);
+static p_mercury(double map[], double *dl, double *dr);
+static p_venus(double t, double mas, double map[],
+	       double *dl, double *dr, double *dml, double *dm);
+static p_mars(double mas, double map[],
+	      double *dl, double *dr, double *dml, double *dm);
+static p_jupiter(double t, double s,
+		 double *dml, double *ds, double *dm, double *da);
+static p_saturn(double t, double s,
+		double *dml, double *ds, double *dm, double *da, double *dhl);
+static p_uranus(double t, double s,
+		double *dl, double* dr, double* dml, double* ds,
+		double* dm, double* da, double* dhl);
+static p_neptune(double t, double s,
+		 double* dl, double* dr, double* dml, double* ds,
+		 double* dm, double* da, double* dhl);
+
 #define	TWOPI		(2*PI)
 #define	mod2PI(x)	((x) - (long)((x)/TWOPI)*TWOPI)
 
