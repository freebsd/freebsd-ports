--- assa/INETAddress.cpp.orig	Thu Jan 22 23:53:34 2004
+++ assa/INETAddress.cpp	Thu Jan 22 23:53:45 2004
@@ -14,6 +14,7 @@
 
 #include <netdb.h>				// gethostbyname(3)
 extern int h_errno;				// gethostbyname(3)
+#include <sys/types.h>
 #include <sys/socket.h>			// for AF_INET
 #include <unistd.h>
 #include <sys/utsname.h>
