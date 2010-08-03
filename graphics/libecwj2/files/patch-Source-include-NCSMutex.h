--- Source/include/NCSMutex.h.orig	2009-04-05 21:26:21.000000000 +0400
+++ Source/include/NCSMutex.h	2009-04-05 21:27:18.000000000 +0400
@@ -114,7 +114,7 @@
 
 #define NCS_NULL_MUTEX { PTHREAD_MUTEX_INITIALIZER }
 
-#elif defined LINUX
+#elif defined LINUX || defined FREEBSD
 
 #define NCS_NULL_MUTEX  PTHREAD_MUTEX_INITIALIZER 
 
@@ -123,7 +123,7 @@
 
 #else /* MACINTOSH */
 
-ERROR: Define NCS_NULL_MUTEX for this platform
+#error Define NCS_NULL_MUTEX for this platform
 
 #endif /* WIN32 */
 
