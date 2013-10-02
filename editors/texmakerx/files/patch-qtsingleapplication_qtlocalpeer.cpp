--- qtsingleapplication/qtlocalpeer.cpp.orig	2013-10-02 07:36:54.000000000 +0000
+++ qtsingleapplication/qtlocalpeer.cpp
@@ -56,6 +56,7 @@ typedef BOOL(WINAPI*PProcessIdToSessionI
 static PProcessIdToSessionId pProcessIdToSessionId = 0;
 #endif
 #if defined(Q_OS_UNIX)
+#include <unistd.h>
 #include <time.h>
 #endif
 
