--- src/engine/proxy.cpp.orig	2016-02-02 04:43:36 UTC
+++ src/engine/proxy.cpp
@@ -4,6 +4,8 @@
   #include <libfilezilla/private/windows.hpp>
   #include <winsock2.h>
   #include <ws2tcpip.h>
+#else
+  #include <sys/socket.h>
 #endif
 #include <filezilla.h>
 #include "engineprivate.h"
