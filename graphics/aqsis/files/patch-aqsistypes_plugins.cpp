--- aqsistypes/plugins.cpp.orig	2007-12-13 22:54:31.000000000 +0100
+++ aqsistypes/plugins.cpp	2007-12-13 22:55:24.000000000 +0100
@@ -170,7 +170,7 @@
 	LocalFree( lpMsgBuf );
 #elif not defined AQSIS_SYSTEM_MACOSX
 
-	char* error = dlerror();
+	const char* error = dlerror();
 	if( error )
 		errorlog = error;
 #endif
