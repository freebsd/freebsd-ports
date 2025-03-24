--- src/server/qgsfcgiserverresponse.cpp.orig	2025-03-21 12:35:59 UTC
+++ src/server/qgsfcgiserverresponse.cpp
@@ -23,6 +23,7 @@
 #include "qgsmessagelog.h"
 #include <fcgi_stdio.h>
 #include <QDebug>
+#include <QThread>
 
 #include "qgslogger.h"
 
@@ -114,7 +115,7 @@ void QgsSocketMonitoringThread::run()
   }
 
 #if defined( Q_OS_UNIX ) && !defined( Q_OS_ANDROID )
-  const pid_t threadId = gettid();
+  quint64 threadId = reinterpret_cast<quint64>( QThread::currentThreadId() );
 
   mShouldStop.store( false );
   char c;
