--- src/MACLib/WAVInputSource.cpp.orig	Wed May 12 06:35:57 2004
+++ src/MACLib/WAVInputSource.cpp	Mon Aug  9 20:27:58 2004
@@ -47,7 +47,7 @@
         pExtension--;
 
     // create the proper input source
-    if (wcsicmp(pExtension, L".wav") == 0)
+    if (wcscmp(pExtension, L".wav") == 0)
     {
         if (pErrorCode) *pErrorCode = ERROR_SUCCESS;
         return new CWAVInputSource(pSourceName, pwfeSource, pTotalBlocks, pHeaderBytes, pTerminatingBytes, pErrorCode);
