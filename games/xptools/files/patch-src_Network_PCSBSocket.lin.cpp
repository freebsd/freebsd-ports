--- src/Network/PCSBSocket.lin.cpp.orig	2017-04-14 14:21:02 UTC
+++ src/Network/PCSBSocket.lin.cpp
@@ -30,9 +30,6 @@
 #include <netinet/in.h>
 #include <netinet/tcp.h>
 #include <sys/ioctl.h>
-#if LIN
-	#include <asm/ioctls.h>
-#endif
 #include <arpa/inet.h>
 #include <netdb.h>
 #include <unistd.h>
