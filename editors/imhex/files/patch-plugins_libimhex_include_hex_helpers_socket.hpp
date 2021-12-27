--- plugins/libimhex/include/hex/helpers/socket.hpp.orig	2021-12-16 17:57:41 UTC
+++ plugins/libimhex/include/hex/helpers/socket.hpp
@@ -14,6 +14,7 @@
 #else
     #include <unistd.h>
     #include <sys/socket.h>
+    #include <netinet/in.h>
     #include <netinet/ip.h>
     #include <arpa/inet.h>
 
