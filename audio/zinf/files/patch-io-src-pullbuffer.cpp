--- io/src/pullbuffer.cpp.orig	Sat Mar 15 10:01:51 2003
+++ io/src/pullbuffer.cpp	Thu Aug 21 21:53:22 2003
@@ -26,6 +26,10 @@
 #include <stdlib.h>
 #include <string.h>
 #include <assert.h>
+#include <inttypes.h>
+#if HAVE_STDINT_H
+#include <stdint.h>
+#endif
 #ifndef WIN32
 #include <unistd.h>
 #endif
@@ -168,7 +172,7 @@
 
    pPtr = (char *)pBuffer;
 
-   if (pPtr >= (char *)((unsigned int)m_pPullBuffer + m_iBufferSize))
+   if (pPtr >= (char *)((uintptr_t)m_pPullBuffer + m_iBufferSize))
 	   pPtr -= m_iBufferSize;
 
    pBuffer = (void *)pPtr;
