--- ./src/qmidinetUdpDevice.cpp.orig	2014-06-27 22:15:38.224214098 +0100
+++ ./src/qmidinetUdpDevice.cpp	2014-06-27 22:16:02.128215458 +0100
@@ -25,6 +25,8 @@
 #include <stdlib.h>
 #include <string.h>
 
+#include <netinet/in.h>
+
 #if defined(WIN32)
 static WSADATA g_wsaData;
 typedef int socklen_t;
