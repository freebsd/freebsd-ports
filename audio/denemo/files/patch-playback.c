--- playback.c.orig	Tue Jun 27 22:13:08 2000
+++ playback.c	Sat Feb 10 19:34:55 2001
@@ -18,7 +18,7 @@
 #include <stdlib.h>
 #include <unistd.h>
 #include <sys/types.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <errno.h>
 
 extern char **environ;		/* I don't know why this is here. Hiller 19 Apr 2000 */
