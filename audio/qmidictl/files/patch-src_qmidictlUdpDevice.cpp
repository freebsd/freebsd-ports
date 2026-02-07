--- src/qmidictlUdpDevice.cpp.orig	2019-02-11 18:29:43 UTC
+++ src/qmidictlUdpDevice.cpp
@@ -40,6 +40,10 @@ inline void closesocket(int s) { ::close
 #endif
 #endif
 
+#if defined(__FreeBSD__)
+#include <netinet/in.h>
+#endif
+
 #include <QByteArray>
 #include <QThread>
 
