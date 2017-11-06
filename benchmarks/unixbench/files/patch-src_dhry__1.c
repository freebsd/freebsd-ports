--- src/dhry_1.c.orig	2015-06-04 17:20:18 UTC
+++ src/dhry_1.c
@@ -34,6 +34,7 @@
  ***************************************************************************/
 char SCCSid[] = "@(#) @(#)dhry_1.c:3.4 -- 5/15/91 19:30:21";
 
+#include <sys/types.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -81,7 +82,7 @@ extern  int     times ();
                 /* Measurements should last at least about 2 seconds */
 #endif
 #ifdef TIME
-extern long     time();
+extern time_t     time();
                 /* see library function "time"  */
 #define Too_Small_Time 2
                 /* Measurements should last at least 2 seconds */
