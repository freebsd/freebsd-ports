--- qterm/qtermtelnet.h.orig	Tue Mar 16 12:17:41 2004
+++ qterm/qtermtelnet.h	Tue Mar 16 12:18:02 2004
@@ -9,8 +9,8 @@
 #elif defined(Q_OS_BSD4) || defined(_OS_FREEBSD_) \
 	|| defined(Q_OS_MACX) || defined(Q_OS_DARWIN)
 	#include <netdb.h>
-	#include <sys/socket.h>
 	#include <sys/types.h>
+	#include <sys/socket.h>
 	#include <netinet/in.h>
 #else
 	#include <netdb.h>
