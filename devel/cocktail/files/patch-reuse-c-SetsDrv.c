--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/SetsDrv.c	Tue Feb 15 14:26:39 1994
+++ ./reuse/c/SetsDrv.c	Fri Sep 10 13:35:03 2004
@@ -35,7 +35,8 @@
 
 /* Ich, Doktor Josef Grosch, Informatiker, Sept. 1987 */
 
-static char rcsid [] = "$Id: SetsDrv.c,v 1.9 1993/08/20 08:12:15 grosch rel $";
+# include <sys/cdefs.h>
+__RCSID("$Id: SetsDrv.c,v 1.9 1993/08/20 08:12:15 grosch rel $");
 
 # include "ratc.h"
 # include <stdio.h>
@@ -47,7 +48,7 @@
 static	long		i	;
 static	FILE *		f	;
 
-main ()
+int main (void)
 {
    MakeSet (& s, max);
    MakeSet (& t, max);
@@ -99,7 +100,7 @@
 
    for (;;) {
       (void) printf ("\n");
-      (void) scanf ("%d", & i);
+      (void) scanf ("%ld", & i);
       if (i == 0) break;
       MakeSet	(& s, (short) i);
       ReadSet	(stdin, & s);
