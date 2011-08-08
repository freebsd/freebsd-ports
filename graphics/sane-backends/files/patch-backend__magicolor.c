--- backend/magicolor.c.orig	2011-01-31 03:49:46.000000000 +0900
+++ backend/magicolor.c	2011-08-02 02:38:15.000000000 +0900
@@ -50,6 +50,8 @@
 #include <unistd.h>
 #include <errno.h>
 #include <sys/time.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 #include <math.h>
 #include <poll.h>
 
