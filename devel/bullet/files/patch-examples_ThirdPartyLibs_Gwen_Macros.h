--- examples/ThirdPartyLibs/Gwen/Macros.h.orig	2021-05-07 18:04:02 UTC
+++ examples/ThirdPartyLibs/Gwen/Macros.h
@@ -41,7 +41,7 @@
 #define GwenUtil_OutputDebugWideString(lpOutputString)  //wprintf( lpOutputString  )
 #define GwenUtil_WideStringToFloat(_Str) wcstof(_Str, NULL)
 
-#elif defined(__linux__) || defined(__GNUC__)
+#elif defined(__linux__) || defined(__GNUC__) || defined(__FreeBSD__)
 
 #define GwenUtil_VSNPrintFSafe(_DstBuf, _DstSize, _MaxCount, _Format, _ArgList) vsnprintf(_DstBuf, _DstSize, _Format, _ArgList)
 #ifdef _WIN32
