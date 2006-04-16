--- backgammon/backgammon/main.c.orig	Tue Nov 11 10:46:54 2003
+++ backgammon/backgammon/main.c	Sun Apr 16 21:21:01 2006
@@ -53,6 +53,8 @@
 #include <signal.h>
 #include "back.h"
 
+#define gtty(_a,_b) ioctl(_a,TIOCGETP,_b)
+
 #define MVPAUSE	5				/* time to sleep when stuck */
 #define MAXUSERS 35				/* maximum number of users */
 
