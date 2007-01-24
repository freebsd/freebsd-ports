diff -u altmenus.c.orig altmenus.c
--- altmenus.c.orig	Sat Mar 14 23:21:53 1992
+++ altmenus.c	Sun Jan 21 20:31:43 2007
@@ -8,6 +8,13 @@
 #include "circum.h"
 #include "screen.h"
 
+static alt1_labels();
+static alt2_labels();
+static alt3_labels();
+static alt1_body (int p, int force, Now *np);
+static alt2_body (int p, int force, Now *np);
+static alt3_body (int p, int force, Now *np);
+
 static int altmenu = F_MNU1;	/* which alternate menu is up; one of F_MNUi */
 static int alt2_stdhzn;	/* whether to use STDHZN (aot ADPHZN) horizon algthm  */
 static int alt3_geoc;	/* whether to use geocentric (aot topocentric) vantage*/
