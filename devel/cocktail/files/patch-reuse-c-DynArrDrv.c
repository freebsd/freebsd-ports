--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/DynArrDrv.c	Tue Feb 15 14:26:33 1994
+++ ./reuse/c/DynArrDrv.c	Fri Sep 10 13:35:02 2004
@@ -23,7 +23,8 @@
 
 /* Ich, Doktor Josef Grosch, Informatiker, Sept. 1987 */
 
-static char rcsid [] = "$Id: DynArrDrv.c,v 1.5 1993/08/18 15:01:05 grosch rel $";
+# include <sys/cdefs.h>
+__RCSID("$Id: DynArrDrv.c,v 1.5 1993/08/18 15:01:05 grosch rel $");
 
 # include "ratc.h"
 # include "DynArray.h"
