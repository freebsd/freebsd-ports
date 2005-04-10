--- libaqsistypes/plugins.cpp.orig	Sun Apr 10 08:35:35 2005
+++ libaqsistypes/plugins.cpp	Sun Apr 10 08:35:58 2005
@@ -153,7 +153,7 @@
     // Free the buffer.
     LocalFree( lpMsgBuf );
 #elif not defined AQSIS_SYSTEM_MACOSX
-    char* error = dlerror();
+    const char* error = dlerror();
     if( error )
 	    errorlog = error;
 #endif
