--- src/qtsingleapplication/qtlocalpeer.cpp.orig	2010-07-13 10:30:19.000000000 +0000
+++ src/qtsingleapplication/qtlocalpeer.cpp
@@ -56,6 +56,7 @@ typedef BOOL(WINAPI*PProcessIdToSessionI
 static PProcessIdToSessionId pProcessIdToSessionId = 0;
 #endif
 #if defined(Q_OS_UNIX)
+#include <unistd.h>
 #include <time.h>
 #endif
 
