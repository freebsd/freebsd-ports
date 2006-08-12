--- aa.c.orig	Sun Nov  1 01:35:05 1998
+++ aa.c	Fri Aug 11 13:21:19 2006
@@ -37,9 +37,7 @@
  */
 #include "kep.h"
 
-#ifdef __BORLANDC__
 #include <stdlib.h>
-#endif
 
 #ifdef _MSC_VER
 #if _MSC_VER >= 1000
