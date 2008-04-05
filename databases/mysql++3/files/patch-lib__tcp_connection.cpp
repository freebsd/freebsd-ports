--- ./lib/tcp_connection.cpp.orig	2008-03-23 08:50:35.000000000 +0200
+++ ./lib/tcp_connection.cpp	2008-04-03 23:34:01.000000000 +0300
@@ -30,6 +30,7 @@
 #include "exceptions.h"
 
 #if !defined(MYSQLPP_PLATFORM_WINDOWS)
+#	include <arpa/inet.h>
 #	include <netdb.h>
 #endif
 
