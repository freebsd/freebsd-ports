--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/Time.h	Tue Feb 15 14:26:41 1994
+++ ./reuse/c/Time.h	Fri Sep 10 13:35:03 2004
@@ -1,13 +1,9 @@
 # ifndef yyTime
 # define yyTime
 
-# ifdef __STDC__
-# define ARGS(parameters)	parameters
-# else
-# define ARGS(parameters)	()
-# endif
+#include "ratc.h"
 
-extern long	StepTime	();
+extern long	StepTime	(NOARGS);
 			/* Returns the sum of user time and system time */
 			/* since the last call to 'StepTime' in milli-	*/
 			/* seconds.					*/
