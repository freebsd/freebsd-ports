--- phoon.c.orig	Sun Mar  6 22:33:22 2005
+++ phoon.c	Sun Mar  6 22:33:45 2005
@@ -354,7 +354,7 @@
     struct tm* tmP;
     double jd, pctphase, angphase, cphase, aom, cdist, cangdia, csund, csuang;
     double phases[2], which[2];
-    long clocknow;
+    time_t clocknow;
     int atflrlen, atflridx, numcols, lin, col, midlin;
     double mcap, yrad, xrad, y, xright, xleft;
     int colright, colleft;
