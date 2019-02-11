--- src/qmidictlUdpDevice.h.orig	2019-02-11 18:32:44 UTC
+++ src/qmidictlUdpDevice.h
@@ -36,6 +36,10 @@
 #endif
 #endif
 
+#if defined(__FreeBSD__)
+#include <netinet/in.h>
+#endif
+
 #include <QObject>
 #include <QString>
 
