--- src/qjackctl.cpp.orig	2015-10-28 15:24:52 UTC
+++ src/qjackctl.cpp
@@ -30,6 +30,10 @@
 
 #include <QSessionManager>
 
+#ifdef HAVE_UNISTD_H
+#include <unistd.h>
+#endif
+
 #if QT_VERSION < 0x040500
 namespace Qt {
 const WindowFlags WindowCloseButtonHint = WindowFlags(0x08000000);
@@ -216,7 +220,7 @@ public:
 			sUnique += sServerName;
 		}
 		char szHostName[255];
-		if (::gethostname(szHostName, sizeof(szHostName)) == 0) {
+		if (gethostname(szHostName, sizeof(szHostName)) == 0) {
 			sUnique += '@';
 			sUnique += szHostName;
 		}
