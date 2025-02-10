--- src/Platform.cpp.orig	2024-09-12 07:10:37 UTC
+++ src/Platform.cpp
@@ -19,6 +19,10 @@
 #include "Platform.h"
 #include "CommonUtility/utils/PathUtils.h"
 #include <fstream>
+#ifdef __FreeBSD__
+#include <pthread_np.h>
+#define	pthread_tryjoin_np(tid,st)	pthread_peekjoin_np(tid,st)
+#endif
 #ifndef WIN32
 errno_t fopen_s(
     FILE** pFile,
@@ -102,7 +106,7 @@ DWORD ES2WaitForSingleObject(
   case THREAD_HANDLE_ID:
   {
    LPTHREAD_HANDLE hThreadHandle = (LPTHREAD_HANDLE) hHandle;
-   if( (int)NULL == hThreadHandle->threadID ) {
+   if( 0 == hThreadHandle->threadID ) {
     return WAIT_OBJECT_0;
    }
    int thread_status = 0;
@@ -118,7 +122,7 @@ DWORD ES2WaitForSingleObject(
     {
      intptr_t lRet = (intptr_t)pStatus;
      hThreadHandle->dwThreadStatus = (DWORD)lRet;
-     hThreadHandle->threadID = (int)NULL;
+     hThreadHandle->threadID = 0;
     }
    }
    while (EBUSY == thread_status);
@@ -177,7 +181,7 @@ BOOL CloseHandle(HANDLE hObject)
     ES2WaitForSingleObject(hObject, INFINITE);
     LPTHREAD_HANDLE pThreadHandle = (LPTHREAD_HANDLE)hObject;
     pThreadHandle->dwThreadStatus = 0;
-    pThreadHandle->threadID = (int)NULL;
+    pThreadHandle->threadID = 0;
 #endif
    }
     break;
@@ -325,14 +329,14 @@ errno_t strcat_s(
  }
  if (NULL == strSource)
  {
-  strDestination[0] = (char)NULL;
+  strDestination[0] = '\0';
   return EINVAL;
  }
  if ( (0 == numberOfElements)
   || (numberOfElements <= (strlen(strDestination) + strlen(strSource)))
   )
  {
-  strDestination[0] = (char)NULL;
+  strDestination[0] = '\0';
   return ERANGE;
  }
  strcat(strDestination, strSource);
