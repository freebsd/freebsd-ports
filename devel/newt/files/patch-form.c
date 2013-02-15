--- form.c.orig	Tue Jun 11 22:15:33 2002
+++ form.c	Sat Jun 22 06:36:12 2002
@@ -10,7 +10,6 @@
 #endif
 #include <sys/time.h>
 
-#ifdef USE_GPM
 #include <ctype.h>
 #include <sys/time.h>      /* timeval */
 #include <sys/socket.h>    /* socket() */
@@ -19,11 +18,9 @@
 #include <sys/stat.h>      /* stat() */
 #include <termios.h>       /* winsize */
 #include <unistd.h>
-#include <sys/kd.h>        /* KDGETMODE */
 #include <signal.h>
+#include <string.h>
 #include <stdio.h>
-#endif
-
 #include "newt.h"
 #include "newt_pr.h"
 
