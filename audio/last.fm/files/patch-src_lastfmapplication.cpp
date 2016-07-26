--- src/lastfmapplication.cpp.orig	2016-07-26 15:06:09 UTC
+++ src/lastfmapplication.cpp
@@ -55,6 +55,10 @@
 #include <QTcpSocket>
 #include <QTimer>
 
+#ifdef Q_OS_UNIX
+    #include <unistd.h>
+#endif
+
 #ifdef WIN32
     #include <windows.h>
 #endif
