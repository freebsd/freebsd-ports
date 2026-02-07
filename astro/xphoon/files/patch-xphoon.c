--- xphoon.c.orig	2000-06-13 21:50:16 UTC
+++ xphoon.c
@@ -20,7 +20,6 @@ static char rcsid[] =
 #include "vroot.h"
 #include <stdio.h>
 #include <stdlib.h>	/* added by David Frey */
-#include <malloc.h>	/* added by David Frey */
 #include <time.h>	/* added by David Frey */
 #include <math.h>
 #include <limits.h>	/* added by Lalo Martins */
@@ -65,7 +64,7 @@ main( argc, argv )
     int blackflag, demoflag, southflag;
     int printpid;
     char* display_name;
-    long clock;
+    time_t clock;
     int pid, tty;
     int size;
     char* mooncopy;
