--- include/numprocessors.h	2009-05-12 21:45:28.000000000 -0500
+++ include/numprocessors.h	2009-05-12 21:46:26.000000000 -0500
@@ -9,7 +9,7 @@
 	#define QMP_USE_WINDOWS_THREADS
 	#include <windows.h>
 	#include <process.h>
-#elif defined(__APPLE__)
+#elif defined(__APPLE__) || defined(__FreeBSD__)
 	#include <pthread.h>
 
 	// Required to get number of processors on OS X using sysctlbyname.
@@ -29,7 +29,7 @@
 		SYSTEM_INFO systemInfo;
 		GetSystemInfo(&systemInfo);
 		return (unsigned int)systemInfo.dwNumberOfProcessors;
-#elif defined (__APPLE__)
+#elif defined (__APPLE__) || defined (__FreeBSD__)
 		int numProcessors = 0;
 		size_t size = sizeof(numProcessors);
 		int returnCode = sysctlbyname("hw.ncpu", &numProcessors, &size, NULL, 0);
