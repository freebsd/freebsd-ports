--- BlockOut/Http.cpp.orig	2014-05-06 16:47:54.000000000 +0700
+++ BlockOut/Http.cpp	2015-08-17 10:39:47.000000000 +0600
@@ -25,6 +25,7 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netdb.h>
+#include <netinet/in.h>
 #define closesocket close
 #else
 #include <Winsock2.h>
@@ -46,6 +47,10 @@
 #define WAIT_FOR_READ  1
 #define WAIT_FOR_WRITE 2
 
+#ifndef ENOSR
+#define ENOSR 9922
+#endif
+
 // -------------------------------------------------------
 
 Http::Http() {
