--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/Positions.c	Tue Feb 15 14:26:37 1994
+++ ./reuse/c/Positions.c	Fri Sep 10 13:35:03 2004
@@ -17,7 +17,8 @@
 
 /* Ich, Doktor Josef Grosch, Informatiker, Juli 1992 */
 
-static char rcsid [] = "$Id: Positions.c,v 1.3 1993/08/18 15:01:05 grosch rel $";
+# include <sys/cdefs.h>
+__RCSID("$Id: Positions.c,v 1.3 1993/08/18 15:01:05 grosch rel $");
 
 # include "Positions.h"
 
@@ -25,7 +26,7 @@
 
 int Compare
 # if defined __STDC__ | defined __cplusplus
-   (tPosition Position1, tPosition Position2)
+   (const tPosition Position1, const tPosition Position2)
 # else
    (Position1, Position2) tPosition Position1, Position2;
 # endif
