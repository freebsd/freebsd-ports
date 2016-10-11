--- common/umutex.cpp.orig	2016-03-23 20:50:10 UTC
+++ common/umutex.cpp
@@ -264,19 +264,19 @@ static pthread_cond_t initCondition = PT
 U_COMMON_API UBool U_EXPORT2
 umtx_initImplPreInit(UInitOnce &uio) {
     pthread_mutex_lock(&initMutex);
-    int32_t state = uio.fState;
+    int32_t state = umtx_loadAcquire(uio.fState);
     if (state == 0) {
         umtx_storeRelease(uio.fState, 1);
         pthread_mutex_unlock(&initMutex);
         return TRUE;   // Caller will next call the init function.
     } else {
-        while (uio.fState == 1) {
+        while (umtx_loadAcquire(uio.fState) == 1) {
             // Another thread is currently running the initialization.
             // Wait until it completes.
             pthread_cond_wait(&initCondition, &initMutex);
         }
         pthread_mutex_unlock(&initMutex);
-        U_ASSERT(uio.fState == 2);
+        U_ASSERT(umtx_loadAcquire(uio.fState) == 2);
         return FALSE;
     }
 }
