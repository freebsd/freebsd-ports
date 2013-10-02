--- src/qtlocalpeer.cpp.orig	2011-06-03 10:11:13.000000000 +0000
+++ src/qtlocalpeer.cpp
@@ -49,6 +49,7 @@ typedef BOOL(WINAPI*PProcessIdToSessionI
 static PProcessIdToSessionId pProcessIdToSessionId = 0;
 #endif
 #if defined(Q_OS_UNIX)
+#include <unistd.h>
 #include <time.h>
 #endif
 
