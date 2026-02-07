--- src/FDM/JSBSim/input_output/FGfdmSocket.h.orig	2025-06-26 10:59:25 UTC
+++ src/FDM/JSBSim/input_output/FGfdmSocket.h
@@ -44,6 +44,8 @@ INCLUDES
 #if defined(_MSC_VER) || defined(__MINGW32__)
   #include <winsock.h>
   #include <io.h>
+#elif defined(__FreeBSD__)
+  #include <netinet/in.h>
 #else
   #include <netdb.h>
 #endif
