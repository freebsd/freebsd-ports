--- ./src/qtlocalpeer.cpp.orig	2011-06-03 10:11:13.000000000 +0000
+++ ./src/qtlocalpeer.cpp	2013-09-30 04:50:58.418156167 +0000
@@ -41,6 +41,7 @@
 #include "qtlocalpeer.h"
 #include <QtCore/QCoreApplication>
 #include <QtCore/QTime>
+#include <unistd.h>
 
 #if defined(Q_OS_WIN)
 #include <QtCore/QLibrary>
@@ -93,7 +94,7 @@
         socketName += QLatin1Char('-') + QString::number(sessionId, 16);
     }
 #else
-    socketName += QLatin1Char('-') + QString::number(::getuid(), 16);
+    socketName += QLatin1Char('-') + QString::number(getuid(), 16);
 #endif
 
     server = new QLocalServer(this);
