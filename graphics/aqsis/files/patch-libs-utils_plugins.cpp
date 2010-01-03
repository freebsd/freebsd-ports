--- libs/util/plugins.cpp.orig	2009-12-31 13:32:11.000000000 +0100
+++ libs/util/plugins.cpp	2009-12-31 13:32:32.000000000 +0100
@@ -170,7 +170,7 @@
 	LocalFree( lpMsgBuf );
 #else //not defined AQSIS_SYSTEM_MACOSX
 
-	char* error = dlerror();
+	const char* error = dlerror();
 	if( error )
 		errorlog = error;
 #endif
