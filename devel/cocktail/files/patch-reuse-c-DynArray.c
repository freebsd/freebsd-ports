--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/DynArray.c	Tue Feb 15 14:26:34 1994
+++ ./reuse/c/DynArray.c	Fri Sep 10 13:35:02 2004
@@ -29,7 +29,8 @@
 
 /* Ich, Doktor Josef Grosch, Informatiker, Sept. 1987 */
 
-static char rcsid [] = "$Id: DynArray.c,v 1.7 1993/08/18 15:01:05 grosch rel $";
+# include <sys/cdefs.h>
+__RCSID("$Id: DynArray.c,v 1.7 1993/08/18 15:01:05 grosch rel $");
 
 # include "ratc.h"
 # include "DynArray.h"
@@ -39,8 +40,7 @@
 
 /* INVARIANT ElmtCount * AlignedSize (ElmtSize) % sizeof (long) == 0 */
 
-static unsigned long AlignedSize (ElmtSize)
-   unsigned long	ElmtSize;
+static unsigned long AlignedSize ( unsigned long	ElmtSize)
    {
       register unsigned long Align;
 
