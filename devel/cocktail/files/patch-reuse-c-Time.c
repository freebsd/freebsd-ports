--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/Time.c	Tue Feb 15 14:26:41 1994
+++ ./reuse/c/Time.c	Fri Sep 10 13:35:03 2004
@@ -1,4 +1,5 @@
-static char rcsid [] = "$Id: Time.c,v 1.6 1993/08/18 15:01:05 grosch rel $";
+# include <sys/cdefs.h>
+__RCSID("$Id: Time.c,v 1.6 1993/08/18 15:01:05 grosch rel $");
 
 # include "Time.h"
 # include <stdio.h>
@@ -8,7 +9,7 @@
 
 long StepTime ()
 {
-   long new = Time ();
+   long new = rTime ();
    long result = new - old;
    old = new;
    return result;
