--- libaqsistypes/plugins.cpp.orig	Fri Jul 23 23:50:39 2004
+++ libaqsistypes/plugins.cpp	Tue Aug 17 14:10:36 2004
@@ -150,7 +150,7 @@
     // Free the buffer.
     LocalFree( lpMsgBuf );
 #elif not defined AQSIS_SYSTEM_MACOSX
-    char* error = dlerror();
+    const char* error = dlerror();
     if( dlerror )
 	    errorlog = error;
 #endif
