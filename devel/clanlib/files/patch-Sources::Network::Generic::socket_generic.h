--- Sources/Network/Generic/socket_generic.h.orig	Thu Jan 22 08:21:55 2004
+++ Sources/Network/Generic/socket_generic.h	Thu Jan 22 08:22:06 2004
@@ -21,6 +21,7 @@
 #include <stack>
 
 #ifndef WIN32
+	#include <sys/types.h>
 	#include <sys/socket.h>
 	#include <netinet/in.h>
 	#include <arpa/inet.h>
