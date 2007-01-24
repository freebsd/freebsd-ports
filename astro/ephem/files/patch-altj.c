diff -u altj.c.orig altj.c
--- altj.c.orig	Sat Mar 14 23:21:51 1992
+++ altj.c	Sun Jan 21 20:32:47 2007
@@ -6,6 +6,12 @@
 #include "circum.h"
 #include "screen.h"
 
+static jupinfo (double d,
+		double *ix, double *ex, double *gx, double *cx,
+		double *iy, double *ey, double *gy, double *cy,
+		double *iz, double *ez, double *gz, double *cz,
+		double *sIcml, double *sIIcml);
+
 altj_labels()
 {
 	static char grs[] = "(GRS is at approximately 30 degs in System II)";
