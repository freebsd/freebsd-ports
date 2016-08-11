--- phoon.c.orig	2005-05-20 19:10:24 UTC
+++ phoon.c
@@ -354,7 +354,7 @@ putmoon( time_t t, int numlines, char* a
     struct tm* tmP;
     double jd, pctphase, angphase, cphase, aom, cdist, cangdia, csund, csuang;
     double phases[2], which[2];
-    long clocknow;
+    time_t clocknow;
     int atflrlen, atflridx, numcols, lin, col, midlin;
     double mcap, yrad, xrad, y, xright, xleft;
     int colright, colleft;
