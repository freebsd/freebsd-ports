--- src/sm.c.orig	Thu Feb  6 16:05:59 2003
+++ src/sm.c	Mon Oct  6 16:09:35 2003
@@ -25,12 +25,13 @@
 #include "main.h"
 #include <X11/SM/SMlib.h>
 #include <stdio.h>	/* only for printf */
-#include <sys/select.h>	/* for select */
+#include <sys/types.h>	/* only for printf */
+#include <sys/select.h>
+#include <sys/time.h>	
 #include <stdlib.h>	/* for free */
 #include <string.h>	/* for strlen */
 #include <unistd.h>	/* for getuid */
 #include <pwd.h>	/* for getpwuid */
-#include <sys/types.h>	/* for getuid and getpwuid */
 
 static SmcConn xpad_sm_conn = NULL;
 static int xpad_interact_style;
