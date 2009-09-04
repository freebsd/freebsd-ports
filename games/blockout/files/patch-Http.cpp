--- BlockOut/Http.cpp.orig	2009-08-06 15:04:34.000000000 +0700
+++ BlockOut/Http.cpp	2009-08-06 15:14:02.000000000 +0700
@@ -24,11 +24,16 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netdb.h>
+#include <netinet/in.h>
 
 
 #define WAIT_FOR_READ  1
 #define WAIT_FOR_WRITE 2
 
+#ifndef ENOSR
+#define ENOSR 9922
+#endif
+
 // -------------------------------------------------------
 
 Http::Http() {
