--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/Source.c	Tue Feb 15 14:26:39 1994
+++ ./reuse/c/Source.c	Fri Sep 10 13:35:03 2004
@@ -11,7 +11,8 @@
 
 /* Ich, Doktor Josef Grosch, Informatiker, Juli 1992 */
 
-static char rcsid [] = "$Id: Source.c,v 1.1 1993/08/18 15:01:05 grosch rel $";
+# include <sys/cdefs.h>
+__RCSID("$Id: Source.c,v 1.1 1993/08/18 15:01:05 grosch rel $");
 
 # include "Source.h"
 
