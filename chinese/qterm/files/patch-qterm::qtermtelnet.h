--- qterm/qtermtelnet.h.ori	Sat Mar 30 21:15:46 2002
+++ qterm/qtermtelnet.h	Sat Mar 30 21:18:47 2002
@@ -8,8 +8,9 @@
 	#include <winsock2.h>
 #else
 	#include <netdb.h>
-	#include <sys/socket.h>
 	#include <sys/types.h>
+	#include <netinet/in.h>
+	#include <sys/socket.h>
 	#include <arpa/inet.h>
 #endif
 
