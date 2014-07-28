--- objx.c.orig	Sat Mar 14 23:22:15 1992
+++ objx.c	Sun Jan 21 20:59:07 2007
@@ -6,17 +6,20 @@
 #include <stdio.h>
 #include <math.h>
 #include <ctype.h>
-#ifdef VMS
+#if defined(VMS) || defined(unix)
 #include <stdlib.h>
 #endif
+#include <string.h>
 #include "astro.h"
 #include "circum.h"
 #include "screen.h"
 
-extern char *strcat(), *strcpy(), *strncpy(), *getenv();
-
 static char *dbfile;			/* !0 if set by -d option */
+#ifdef unix
+static char dbfdef[] = PREFIX "/share/ephem/ephem.db"; 	/* default database file name */
+#else
 static char dbfdef[] = "ephem.db"; 	/* default database file name */
+#endif
 
 /* structures to describe objects of various types.
  */
@@ -95,6 +98,17 @@
 
 #define	DY	0		/* decimal year flag for set_year() */
 #define	YMD	1		/* year/mon/day flag for set_year() */
+
+static nxt_db(char buf[], int blen, FILE *fp);
+static obj_dfixed(Obj *op, int ac, char *av[]);
+static obj_delliptical(Obj *op, int ac, char *av[]);
+static obj_dhyperbolic(Obj *op, int ac, char *av[]);
+static obj_dparabolic(Obj *op, int ac, char *av[]);
+static set_double(char *av[], int vn, char *pr, double *fp);
+static set_name(char *av[], char *np);
+static set_year(char *av[], int vn, char *pr, int type, double *yp);
+static crack_year(char *bp, double *p);
+static set_mag(char *av[], int vn, Mag *mp);
 
 /* run when Objx or y is picked from menu.
  * we tell which by the planet code.
