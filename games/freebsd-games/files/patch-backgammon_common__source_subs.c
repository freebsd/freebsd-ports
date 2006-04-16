--- backgammon/common_source/subs.c.orig	Mon Apr 22 23:44:18 2002
+++ backgammon/common_source/subs.c	Sun Apr 16 21:27:43 2006
@@ -44,6 +44,8 @@
 #include <string.h>
 #include "back.h"
 
+#define stty(_a,_b) ioctl(_a,TIOCSETP,_b)
+
 int	buffnum;
 char	outbuff[BUFSIZ];
 
