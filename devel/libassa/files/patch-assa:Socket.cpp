--- assa/Socket.cpp.orig	Fri Jul 25 08:51:00 2003
+++ assa/Socket.cpp	Mon Mar 29 12:05:59 2004
@@ -16,6 +16,7 @@
 
 #include <sstream>
 #include <rpc/rpc.h>
+#include <sys/ioctl.h>
 
 #include "assa/Socket.h"
 
@@ -190,7 +191,7 @@
 	int level = SOL_SOCKET;
 	bool bin = false;
 
-	size_t len = sizeof (optval);
+	socklen_t len = sizeof (optval);
 	int ret;
 
 	if (rcvlowat == opt_)      optname = SO_RCVLOWAT;
