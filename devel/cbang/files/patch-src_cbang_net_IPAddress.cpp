--- src/cbang/net/IPAddress.cpp.orig	2021-08-10 22:46:49 UTC
+++ src/cbang/net/IPAddress.cpp
@@ -50,6 +50,9 @@
 #else
 #include <sys/types.h>
 #include <sys/socket.h>
+#  ifdef __FreeBSD__
+#include <netinet/in.h>
+#  endif
 #include <netdb.h>
 #endif
 
