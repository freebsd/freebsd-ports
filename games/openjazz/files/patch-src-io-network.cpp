--- src/io/network.cpp.orig	2010-03-30 17:07:37.715288674 +0000
+++ src/io/network.cpp	2010-03-30 17:13:25.119068484 +0000
@@ -41,6 +41,7 @@
 		#define MSG_NOSIGNAL 0
 	#else
 		#include <sys/types.h>
+		#include <netinet/in.h>
 		#include <sys/socket.h>
 		#include <arpa/inet.h>
 		#include <sys/ioctl.h>
