--- tcp.c.orig	Sat Jan  6 14:53:45 2001
+++ tcp.c	Sat Jan  6 14:53:51 2001
@@ -23,7 +23,7 @@
 #include <string.h>
 #include <unistd.h>
 #include <signal.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/fcntl.h>
