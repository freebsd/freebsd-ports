--- inc/ucommon/socket.h.orig	2014-07-15 09:50:01.000000000 +0200
+++ inc/ucommon/socket.h	2014-07-15 09:51:34.000000000 +0200
@@ -38,6 +38,8 @@
 #include <ucommon/string.h>
 #endif
 
+#include <string>
+
 extern "C" {
     struct addrinfo;
 }
