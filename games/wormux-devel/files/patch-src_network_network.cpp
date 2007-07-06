--- src/network/network.cpp.orig	2007-07-06 22:00:00.000000000 +0000
+++ src/network/network.cpp	2007-07-06 22:01:51.000000000 +0000
@@ -45,6 +45,9 @@
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netdb.h>
+#include <netinet/in.h>                                                                                                                                  
+#include <arpa/nameser.h>                                                                                                                                
+#include <resolv.h>
 #include <errno.h>
 #else
 #include <winsock.h>
