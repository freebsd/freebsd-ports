--- ./phoon.c.orig	2005-05-20 21:10:24.000000000 +0200
+++ ./phoon.c	2014-02-12 22:38:52.438019914 +0100
@@ -354,7 +354,7 @@
     struct tm* tmP;
     double jd, pctphase, angphase, cphase, aom, cdist, cangdia, csund, csuang;
     double phases[2], which[2];
-    long clocknow;
+    time_t clocknow;
     int atflrlen, atflridx, numcols, lin, col, midlin;
     double mcap, yrad, xrad, y, xright, xleft;
     int colright, colleft;
