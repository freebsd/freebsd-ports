--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/rMemoryDrv.c	Tue Feb 15 14:26:42 1994
+++ ./reuse/c/rMemoryDrv.c	Fri Sep 10 13:35:03 2004
@@ -29,7 +29,8 @@
 
 /* Ich, Doktor Josef Grosch, Informatiker, Sept. 1987 */
 
-static char rcsid [] = "$Id: rMemoryDrv.c,v 1.7 1993/08/20 08:13:11 grosch rel $";
+# include <sys/cdefs.h>
+__RCSID("$Id: rMemoryDrv.c,v 1.7 1993/08/20 08:13:11 grosch rel $");
 
 # include "ratc.h"
 # include "rMemory.h"
