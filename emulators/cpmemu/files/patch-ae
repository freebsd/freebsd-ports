--- low.c.orig	Wed Dec 11 22:44:43 2002
+++ low.c	Wed Dec 11 22:44:56 2002
@@ -18,11 +18,10 @@
  * space-invaders-type game working, I think it was. :-)	-rjm
  */
 
+#include <sys/types.h>
 #include "cpmemu.h"
 #include <ctype.h>
 #include <unistd.h>
-#include <sys/perm.h>		/* needed for ioperm() -rjm */
-#include <sys/types.h>
 #include <sys/time.h>
 #include <signal.h>
 #include <sys/mman.h>
@@ -88,10 +87,8 @@
 
     /* get access to sound port */
     cptr = NULL;
-    if (ioperm(0x61, 1, 1)) {
 	hardware_access = 0;	/* no access to speaker port */
 	return;
-    }
 
     /* install signal handler */
     sa.sa_handler = tickerint;
