--- xphoon.c.orig	Thu Sep 19 04:57:37 1991
+++ xphoon.c	Sun Jan  3 18:30:29 1999
@@ -20,7 +20,6 @@
 #include "vroot.h"
 #include <stdio.h>
 #include <stdlib.h>	/* added by David Frey */
-#include <malloc.h>	/* added by David Frey */
 #include <time.h>	/* added by David Frey */
 #include <math.h>
 #include <limits.h>	/* added by Lalo Martins */
@@ -65,7 +74,7 @@
     int blackflag, demoflag;
     int printpid;
     char* display_name;
-    long clock;
+    time_t clock;
     int pid, tty;
     int size;
     char* mooncopy;
