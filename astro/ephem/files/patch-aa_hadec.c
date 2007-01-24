diff -u aa_hadec.c.orig aa_hadec.c
--- aa_hadec.c.orig	Sat Mar 14 23:21:50 1992
+++ aa_hadec.c	Sun Jan 21 20:33:08 2007
@@ -2,6 +2,8 @@
 #include <math.h>
 #include "astro.h"
 
+static aaha_aux (double lat, double x, double y, double *p, double *q);
+
 /* given latitude (n+, radians), lat, altitude (up+, radians), alt, and
  * azimuth (angle round to the east from north+, radians),
  * return hour angle (radians), ha, and declination (radians), dec.
