
$FreeBSD$

--- native/target/generic/target_generic_network.h.orig
+++ native/target/generic/target_generic_network.h
@@ -666,6 +666,7 @@
 #ifndef TARGET_NATIVE_NETWORK_SOCKET_SET_OPTION_SO_TIMEOUT
   #include <sys/types.h>
   #include <sys/socket.h>
+  #include <sys/time.h>
   #define TARGET_NATIVE_NETWORK_SOCKET_SET_OPTION_SO_TIMEOUT(socketDescriptor,flag,result) \
     do { \
       struct timeval __value; \
