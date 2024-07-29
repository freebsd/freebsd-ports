--- ui/zenoedit/launch/ztcpserver.cpp.orig	2024-04-23 11:08:52 UTC
+++ ui/zenoedit/launch/ztcpserver.cpp
@@ -1,4 +1,4 @@
-#if defined(ZENO_MULTIPROCESS) && defined(ZENO_IPC_USE_TCP)
+//#if defined(ZENO_MULTIPROCESS) && defined(ZENO_IPC_USE_TCP)
 #include <cstdio>
 #include <cstring>
 #include "ztcpserver.h"
@@ -443,4 +443,4 @@ void ZTcpServer::onProcFinished(int exitCode, QProcess
         emit runFinished();
 }
 
-#endif
+//#endif
