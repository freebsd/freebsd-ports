--- src/ConnectionRemote/ConnectionRemote.cpp.orig	2020-10-29 09:52:56 UTC
+++ src/ConnectionRemote/ConnectionRemote.cpp
@@ -31,6 +31,10 @@
 #include <Winsock.h>
 #endif // LINUX
 
+#if defined(__FreeBSD__)
+#include <sys/socket.h>
+#endif
+
 using namespace std;
 using namespace lime;
 
