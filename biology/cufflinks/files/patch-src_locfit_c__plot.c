--- src/locfit/c_plot.c.orig	2020-08-28 18:21:05 UTC
+++ src/locfit/c_plot.c
@@ -9,7 +9,7 @@ vari *growvar(vari* vold, int n);
 
 plots *cpl, pl[MAXWIN];
 extern device devps, devwin;
-INT curwin;
+extern INT curwin;
 char *psfn;
 extern lfit lf;
 extern pplot pp;
