--- libs/easywsclient/easywsclient.cpp.orig	2020-07-15 18:02:29 UTC
+++ libs/easywsclient/easywsclient.cpp
@@ -56,6 +56,7 @@
     #include <unistd.h>
     #include <stdint.h>
     #include <netinet/tcp.h>
+    #include <netinet/in.h>
     #include <arpa/inet.h>
 
     #ifndef _SOCKET_T_DEFINED
