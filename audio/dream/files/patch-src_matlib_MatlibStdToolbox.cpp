--- src/matlib/MatlibStdToolbox.cpp.orig	2016-02-26 02:12:16 UTC
+++ src/matlib/MatlibStdToolbox.cpp
@@ -28,11 +28,11 @@
 #include "MatlibStdToolbox.h"
 #include "../GlobalDefinitions.h"
 
-/* The mutex need to be application wide,
+/* The dream_mutex need to be application wide,
    only the execution routines are thread-safe */
-static CMutex* mutex = NULL;
-#define MUTEX_LOCK() mutex->Lock()
-#define MUTEX_UNLOCK() mutex->Unlock()
+static CMutex* dream_mutex = NULL;
+#define MUTEX_LOCK() dream_mutex->Lock()
+#define MUTEX_UNLOCK() dream_mutex->Unlock()
 
 # define PLANNER_FLAGS (FFTW_ESTIMATE | FFTW_DESTROY_INPUT)
 /* Warning: for testing purpose only */
@@ -669,8 +669,8 @@ CFftPlans::CFftPlans(const int iFftSize)
 	bInitialized(FALSE), bFixedSizeInit(FALSE), fftw_n(0)
 {
 	/* Static initialization of CMutex not working on Mac OS X */
-	if (!mutex)
-		mutex = new CMutex();
+	if (!dream_mutex)
+		dream_mutex = new CMutex();
 
 	/* If iFftSize is non zero then proceed to initialization */
 	if (iFftSize)
