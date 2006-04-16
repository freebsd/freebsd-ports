--- backgammon/teachgammon/teach.c.orig	Sat Feb  2 20:37:20 2002
+++ backgammon/teachgammon/teach.c	Sun Apr 16 21:22:11 2006
@@ -52,6 +52,8 @@
 #include <signal.h>
 #include "back.h"
 
+#define gtty(_a,_b) ioctl(_a,TIOCGETP,_b)
+
 extern char	*hello[];
 extern char	*list[];
 extern char	*intro1[];
