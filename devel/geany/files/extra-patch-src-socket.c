--- src/socket.c.orig	Wed Sep 27 00:29:44 2006
+++ src/socket.c	Mon Oct  2 15:40:39 2006
@@ -26,6 +26,9 @@
 #ifdef HAVE_SOCKET
 
 #ifndef G_OS_WIN32
+# include <string.h>
+# include <sys/time.h>
+# include <sys/types.h>
 # include <sys/socket.h>
 # include <sys/un.h>
 # include <netinet/in.h>
