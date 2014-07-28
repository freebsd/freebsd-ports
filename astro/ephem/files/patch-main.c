--- main.c.orig	Sat Mar 14 23:22:10 1992
+++ main.c	Sun Jan 21 20:51:46 2007
@@ -16,15 +16,26 @@
 #include <signal.h>
 #include <setjmp.h>
 #include <math.h>
-#ifdef VMS
+#if defined(VMS) || defined(unix)
 #include <stdlib.h>
 #endif
+#include <time.h>
 #include "astro.h"
 #include "circum.h"
 #include "screen.h"
+#include <string.h>
+#include <stdlib.h>
 
-extern char *strncpy();
-extern char *getenv();
+static read_cfgfile();
+static void on_fpe();
+static read_fieldargs(int ac, char *av[]);
+static crack_fieldset(char *buf);
+static chg_fld(char *bp, int *fld);
+static print_tminc(int force);
+static print_alt(int howmuch);
+static print_nstep(int force);
+static print_spause(int force);
+static toggle_body(int p);
 
 /* shorthands for fields of a Now structure, now.
  * first undo the ones for a Now pointer from circum.h.
@@ -51,7 +62,11 @@
 
 static jmp_buf fpe_err_jmp;	/* used to recover from SIGFPE */
 static char *cfgfile;		/* !0 if -c used */
+#ifdef unix
+static char cfgdef[] = PREFIX "/share/ephem/ephem.cfg"; /* default configuration file name */
+#else
 static char cfgdef[] = "ephem.cfg"; /* default configuration file name */
+#endif
 static Now now;		/* where when and how, right now */
 static double tminc;	/* hrs to inc time by each loop; RTC means use clock */
 static int nstep;	/* steps to go before stopping */
@@ -1006,12 +1021,12 @@
  */
 slp_sync()
 {
-	extern long time();
+	/*extern long time();*/
 
 	if (spause > 0 && !plot_ison() && !srch_ison() && !listing_ison()) {
 	    int n;
 	    if (tminc == RTC) {
-		long t;
+		time_t t;
 		(void) time (&t);
 		n = spause - (t % spause);
 	    } else 
