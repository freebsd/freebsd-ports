--- ui/zenoedit/launch/ztcpserver.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/launch/ztcpserver.cpp
@@ -1,4 +1,4 @@
-#if defined(ZENO_MULTIPROCESS) && defined(ZENO_IPC_USE_TCP)
+//#if defined(ZENO_MULTIPROCESS) && defined(ZENO_IPC_USE_TCP)
 #include <cstdio>
 #include <cstring>
 #include "ztcpserver.h"
@@ -446,4 +446,4 @@ void ZTcpServer::onProcFinished(int exitCode, QProcess
         emit runFinished();
 }
 
-#endif
+//#endif
