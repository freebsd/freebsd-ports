--- qterm/qtermtelnet.h.orig	Sat Apr 12 21:10:39 2003
+++ qterm/qtermtelnet.h	Sat Apr 12 21:11:19 2003
@@ -8,9 +8,9 @@
 	#include <winsock2.h>
 #else
 	#include <netdb.h>
-	#include <sys/socket.h>
 	#include <sys/types.h>
-	#include <arpa/inet.h>
+	#include <sys/socket.h>
+	#include <netinet/in.h>
 #endif
 
 #include <qobject.h>
