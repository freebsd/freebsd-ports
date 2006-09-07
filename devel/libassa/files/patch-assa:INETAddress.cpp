--- assa/INETAddress.cpp.orig	Thu Jul 20 06:13:13 2006
+++ assa/INETAddress.cpp	Wed Sep  6 16:13:15 2006
@@ -17,6 +17,7 @@
 #else
 #   include <netdb.h>				// gethostbyname(3)
 extern int h_errno;				// gethostbyname(3)
+#   include <sys/types.h>			// for AF_INET
 #   include <sys/socket.h>			// for AF_INET
 #   include <unistd.h>
 #   include <sys/utsname.h>
