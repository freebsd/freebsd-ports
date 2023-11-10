--- src/io/network.cpp.orig	2023-10-31 10:46:24 UTC
+++ src/io/network.cpp
@@ -44,6 +44,7 @@
 		#endif
 	#else
 		#include <sys/types.h>
+		#include <netinet/in.h>
 		#include <sys/socket.h>
 		#include <arpa/inet.h>
 		#include <sys/select.h>
