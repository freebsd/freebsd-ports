--- Source/Core/Core/Src/IPC_HLE/WII_Socket.cpp.orig	2013-09-17 16:50:52.000000000 +0200
+++ Source/Core/Core/Src/IPC_HLE/WII_Socket.cpp	2013-09-17 16:51:58.000000000 +0200
@@ -21,6 +21,13 @@
 #define EITHER(win32, posix) posix
 #endif
 
+#if defined __FreeBSD__
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <netinet/in.h>
+#include <arpa/inet.h>
+#endif
+
 char* WiiSockMan::DecodeError(s32 ErrorCode)
 {
 #ifdef _WIN32
