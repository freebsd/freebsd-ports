--- watch.c.orig	Sun Jan 21 21:14:29 2007
+++ watch.c	Sun Jan 21 21:16:30 2007
@@ -51,6 +51,13 @@
 
 static int trails;	/* !0 if want to leave trails */
 
+static watch_sky(int style, Now *np, double tminc, int wbodies);
+static watch_solarsystem(Now *np, double tminc, int wbodies);
+static set_ss(LastDraw *lp, double dist, double lg, double lt, char tag);
+static set_screencoords(LastDraw lp[], int np);
+static safe_f_char(int r, int c, char tag);
+static int readwcmd(double tminc0, double *tminc, int *once);
+
 watch (np, tminc, wbodies)
 Now *np;	/* time now and on each step */
 double tminc;	/* hrs to increment time by each step */
