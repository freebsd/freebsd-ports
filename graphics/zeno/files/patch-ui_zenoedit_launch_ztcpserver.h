--- ui/zenoedit/launch/ztcpserver.h.orig	2024-04-23 11:07:59 UTC
+++ ui/zenoedit/launch/ztcpserver.h
@@ -1,7 +1,7 @@
 #ifndef __ZCORE_TCPSERVER_H__
 #define __ZCORE_TCPSERVER_H__
 
-#if defined(ZENO_MULTIPROCESS) && defined(ZENO_IPC_USE_TCP)
+//#if defined(ZENO_MULTIPROCESS) && defined(ZENO_IPC_USE_TCP)
 
 #include <QObject>
 #include <QtNetwork>
@@ -52,6 +52,6 @@ private slots: (private)
     int m_port;
 };
 
-#endif
+//#endif
 
 #endif
