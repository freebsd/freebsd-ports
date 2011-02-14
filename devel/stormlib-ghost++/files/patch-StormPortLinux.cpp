--- StormPortLinux.cpp
+++ StormPortLinux.cpp
@@ -24,6 +24,7 @@
 *
 ********************************************************************/
 
+#define O_LARGEFILE 0100000
 #ifndef _WIN32
 #include "StormPort.h"
 
@@ -104,8 +105,8 @@
         return 0xffffffff;
     }
 
-    struct stat64 fileinfo;
-    fstat64((intptr_t)hFile, &fileinfo);
+    struct stat fileinfo;
+    fstat((intptr_t)hFile, &fileinfo);
     
     // Fix by Ladik: If "ulOffSetHigh" is not NULL, it needs to be set 
     // to higher 32 bits of a file size.
@@ -118,12 +119,12 @@
 
 DWORD SetFilePointer(HANDLE hFile, LONG lOffSetLow, LONG *pOffSetHigh, DWORD ulMethod)
 {
-    off64_t nFileOffset = (DWORD)lOffSetLow;
+    off_t nFileOffset = (DWORD)lOffSetLow;
 
     if(pOffSetHigh != NULL)
-        nFileOffset |= (*(off64_t *)pOffSetHigh) << 32;
+        nFileOffset |= (*(off_t *)pOffSetHigh) << 32;
 
-    return lseek64((intptr_t)hFile, nFileOffset, ulMethod);
+    return lseek((intptr_t)hFile, nFileOffset, ulMethod);
 }
 
 BOOL SetEndOfFile(HANDLE hFile)
