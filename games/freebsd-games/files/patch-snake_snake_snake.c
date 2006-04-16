--- snake/snake/snake.c.orig	Tue Nov 11 10:47:06 2003
+++ snake/snake/snake.c	Sun Apr 16 21:04:54 2006
@@ -68,6 +68,8 @@
 #include "snake.h"
 #include "pathnames.h"
 
+#define stty(_a,_b) ioctl(_a,TIOCSETP,_b)
+
 #define PENALTY  10	/* % penalty for invoking spacewarp	*/
 
 #define EOT	'\004'
