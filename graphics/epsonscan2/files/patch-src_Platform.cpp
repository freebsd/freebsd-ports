--- src/Platform.cpp.orig	2021-11-25 00:56:59 UTC
+++ src/Platform.cpp
@@ -22,6 +22,10 @@
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
@@ -105,7 +109,7 @@ DWORD WaitForSingleObject(
   case THREAD_HANDLE_ID:
   {
    LPTHREAD_HANDLE hThreadHandle = (LPTHREAD_HANDLE) hHandle;
-   if( (int)NULL == hThreadHandle->threadID ) {
+   if( 0 == hThreadHandle->threadID ) {
     return WAIT_OBJECT_0;
    }
    int thread_status = 0;
@@ -121,7 +125,7 @@ DWORD WaitForSingleObject(
     {
      intptr_t lRet = (intptr_t)pStatus;
      hThreadHandle->dwThreadStatus = (DWORD)lRet;
-     hThreadHandle->threadID = (int)NULL;
+     hThreadHandle->threadID = 0;
     }
    }
    while (EBUSY == thread_status);
@@ -180,7 +184,7 @@ BOOL CloseHandle(HANDLE hObject)
     WaitForSingleObject(hObject, INFINITE);
     LPTHREAD_HANDLE pThreadHandle = (LPTHREAD_HANDLE)hObject;
     pThreadHandle->dwThreadStatus = 0;
-    pThreadHandle->threadID = (int)NULL;
+    pThreadHandle->threadID = 0;
 #endif
    }
     break;
@@ -347,7 +351,11 @@ DWORD GetModuleFileName(LPTSTR lpFilename, DWORD buf_s
 {
  DWORD dwRet = 0;
     memset(lpFilename, 0, buf_size);
+#ifdef __FreeBSD__
+ readlink( "/proc/curproc/file", lpFilename, buf_size - 1 );
+#else
  readlink( "/proc/self/exe", lpFilename, buf_size - 1 );
+#endif
  dwRet = (DWORD)strlen(lpFilename);
  return dwRet;
 }
@@ -397,14 +405,14 @@ errno_t strcat_s(
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
