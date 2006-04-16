--- snake/snake/move.c.orig	Wed May 29 02:54:00 2002
+++ snake/snake/move.c	Sun Apr 16 21:04:37 2006
@@ -103,6 +103,9 @@
 
 #include "snake.h"
 
+#define stty(_a,_b) ioctl(_a,TIOCSETP,_b)
+#define gtty(_a,_b) ioctl(_a,TIOCGETP,_b)
+
 int CMlength;
 int NDlength;
 int BSlength;
