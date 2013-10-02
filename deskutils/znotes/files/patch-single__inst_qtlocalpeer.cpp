--- single_inst/qtlocalpeer.cpp.orig	2011-08-27 08:25:14.000000000 +0000
+++ single_inst/qtlocalpeer.cpp
@@ -58,9 +58,7 @@ static PProcessIdToSessionId pProcessIdT
 #if defined(Q_OS_UNIX)
 #include <time.h>
 #endif
-#if defined(Q_OS_OS2)
 #include <unistd.h>
-#endif
 
 namespace QtLP_Private {
 #include "qtlockedfile.cpp"
