--- Sources/Network/Generic/ip_address.cpp.orig	Thu Jan 22 08:22:51 2004
+++ Sources/Network/Generic/ip_address.cpp	Thu Jan 22 08:23:01 2004
@@ -15,6 +15,7 @@
 #include "API/Core/System/error.h"
 
 #ifndef WIN32
+	#include <sys/types.h>
 	#include <sys/socket.h>
 	#include <netinet/in.h>
 	#include <arpa/inet.h>
