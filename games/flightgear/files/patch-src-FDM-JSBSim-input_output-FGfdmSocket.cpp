--- src/FDM/JSBSim/input_output/FGfdmSocket.cpp.orig	2025-06-26 10:55:02 UTC
+++ src/FDM/JSBSim/input_output/FGfdmSocket.cpp
@@ -40,7 +40,7 @@ INCLUDES
 
 #if defined(_MSC_VER) || defined(__MINGW32__)
 #include <ws2tcpip.h>
-#elif defined(__OpenBSD__)
+#elif defined(__OpenBSD__) || defined(__FreeBSD__)
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netdb.h>
