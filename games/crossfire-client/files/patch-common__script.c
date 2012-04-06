--- ./common/script.c.orig	2011-01-28 00:17:56.000000000 -0600
+++ ./common/script.c	2012-03-17 13:43:59.000000000 -0500
@@ -116,6 +116,7 @@
 
 #ifndef WIN32
 #include <errno.h>
+#include <signal.h>
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <sys/wait.h>
