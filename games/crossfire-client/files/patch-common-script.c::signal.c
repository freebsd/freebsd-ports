--- common/script.c.orig	Fri May  7 07:51:00 2004
+++ common/script.c	Fri May  7 07:51:41 2004
@@ -114,6 +114,8 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/wait.h>
+#include <sys/signal.h>
+#include <signal.h>
 #endif
 
 #include <client.h>
