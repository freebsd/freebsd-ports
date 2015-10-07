--- src/libcore/util.cpp.orig	2015-07-15 10:37:38 UTC
+++ src/libcore/util.cpp
@@ -35,7 +35,7 @@
 #include <direct.h>
 #include <psapi.h>
 #else
-#include <malloc.h>
+#include <stdlib.h>
 #endif
 
 #if defined(__WINDOWS__)
@@ -45,6 +45,7 @@
 #else
 # include <sys/types.h>
 # include <sys/socket.h>
+# include <netinet/in.h>
 # include <netdb.h>
 # include <fenv.h>
 #endif
@@ -132,7 +133,10 @@ void * __restrict allocAligned(size_t si
 	   for AltiVec and SSE computations */
 	return malloc(size);
 #else
-	return memalign(L1_CACHE_LINE_SIZE, size);
+	void *ptr;
+	if (posix_memalign(&ptr, L1_CACHE_LINE_SIZE, size))
+		ptr = NULL;
+	return ptr;
 #endif
 }
 
@@ -172,6 +176,7 @@ int getCoreCount() {
 		/* Some of the cores may not be available to the user
 		   (e.g. on certain cluster nodes) -- determine the number
 		   of actual available cores here. */
+#ifndef __FreeBSD__
 		int nLogicalCores = nCores;
 		size_t size = 0;
 		cpu_set_t *cpuset = NULL;
@@ -208,6 +213,7 @@ int getCoreCount() {
 			availableCores += CPU_ISSET_S(i, size, cpuset) ? 1 : 0;
 		nCores = availableCores;
 		CPU_FREE(cpuset);
+#endif // __FreeBSD__
 	}
 
 done:
