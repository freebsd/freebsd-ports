--- libddmsock/ddmsock.cpp.orig	Sat Sep  6 03:37:58 2003
+++ libddmsock/ddmsock.cpp	Sun Sep 28 22:22:06 2003
@@ -40,6 +40,7 @@
 #include <unistd.h>
 #include <netinet/in.h>
 #include <sys/types.h>
+#include <sys/signal.h>
 #include <sys/socket.h>
 #include <sys/wait.h>
 #include <errno.h>
