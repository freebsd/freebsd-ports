--- lockservice/LockParse.cpp.orig	Thu Mar  4 01:19:43 2004
+++ lockservice/LockParse.cpp	Thu Mar  4 01:19:58 2004
@@ -11,6 +11,7 @@
 #include <sys/socket.h>
 #include <netdb.h>
 #include <errno.h>
+#include <time.h>
 #define SOCKET int
 #endif
 
