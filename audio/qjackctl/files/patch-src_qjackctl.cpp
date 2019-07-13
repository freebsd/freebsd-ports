--- src/qjackctl.cpp.orig	2019-07-12 10:07:12 UTC
+++ src/qjackctl.cpp
@@ -190,7 +190,7 @@ bool qjackctlApplication::setup ( const QString& sServ
 			sUnique += sServerName;
 		}
 		char szHostName[255];
-		if (::gethostname(szHostName, sizeof(szHostName)) == 0) {
+		if (gethostname(szHostName, sizeof(szHostName)) == 0) {
 			sUnique += '@';
 			sUnique += szHostName;
 		}
