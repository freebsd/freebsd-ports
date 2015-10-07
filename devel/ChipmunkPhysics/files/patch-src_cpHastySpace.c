--- src/cpHastySpace.c.orig	2015-07-02 16:24:47 UTC
+++ src/cpHastySpace.c
@@ -5,8 +5,11 @@
 #include <stdio.h>
 
 #include <pthread.h>
-//#include <sys/param.h >
-#include <sys/sysctl.h>
+#ifdef _WIN32
+#include <windows.h>
+#else
+#include <unistd.h>
+#endif
 
 #include "chipmunk/chipmunk_private.h"
 #include "chipmunk/cpHastySpace.h"
@@ -314,14 +317,20 @@ cpHastySpaceSetThreads(cpSpace *space, u
 	cpHastySpace *hasty = (cpHastySpace *)space;
 	HaltThreads(hasty);
 	
-#ifdef __APPLE__
 	if(threads == 0){
+#ifdef __APPLE__
 		size_t size = sizeof(threads);
 		sysctlbyname("hw.ncpu", &threads, &size, NULL, 0);
-	}
+#elif defined(_SC_NPROCESSORS_ONLN)
+		threads = sysconf(_SC_NPROCESSORS_ONLN);
+#elif defined(_WIN32)
+		SYSTEM_INFO siSysInfo;
+		GetSystemInfo(&siSysInfo);
+		threads = siSysInfo.dwNumberOfProcessors;
 #else
-	if(threads == 0) threads = 1;
+		threads = 1;
 #endif
+	}
 	
 	hasty->num_threads = (threads < MAX_THREADS ? threads : MAX_THREADS);
 	hasty->num_working = hasty->num_threads - 1;
