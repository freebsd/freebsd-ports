--- src/lastfmapplication.cpp.orig
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
