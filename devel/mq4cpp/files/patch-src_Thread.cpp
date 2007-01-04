--- src/Thread.cpp.orig	Thu Jan  4 12:31:04 2007
+++ src/Thread.cpp	Thu Jan  4 12:31:22 2007
@@ -76,7 +76,7 @@
 #ifdef WIN32
 	return GetCurrentThreadId();
 #else
-	return pthread_self();
+	return (unsigned long)pthread_self();
 #endif
 }
 
