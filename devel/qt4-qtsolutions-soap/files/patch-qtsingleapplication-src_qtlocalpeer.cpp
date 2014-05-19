--- ../qtsingleapplication/src/qtlocalpeer.cpp.orig	2014-05-07 10:38:16.000000000 +0200
+++ ../qtsingleapplication/src/qtlocalpeer.cpp	2014-05-07 10:38:49.000000000 +0200
@@ -49,6 +49,8 @@
 static PProcessIdToSessionId pProcessIdToSessionId = 0;
 #endif
 #if defined(Q_OS_UNIX)
+#include <unistd.h>
+#include <sys/types.h>
 #include <time.h>
 #endif
 
@@ -93,7 +95,7 @@
         socketName += QLatin1Char('-') + QString::number(sessionId, 16);
     }
 #else
-    socketName += QLatin1Char('-') + QString::number(::getuid(), 16);
+    socketName += QLatin1Char('-') + QString::number(getuid(), 16);
 #endif
 
     server = new QLocalServer(this);
