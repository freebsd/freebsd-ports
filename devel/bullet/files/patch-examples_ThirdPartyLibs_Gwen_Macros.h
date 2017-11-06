--- examples/ThirdPartyLibs/Gwen/Macros.h.orig	2017-02-17 23:43:38 UTC
+++ examples/ThirdPartyLibs/Gwen/Macros.h
@@ -4,9 +4,6 @@
 #define GWEN_MACROS_H
 #include <stdlib.h>
 #include <stdarg.h>
-#ifndef __APPLE__
-#include <malloc.h>
-#endif //__APPLE__
 #include <memory.h>
 #include <algorithm>
 
@@ -38,7 +35,7 @@
 	#define GwenUtil_OutputDebugWideString( lpOutputString ) //wprintf( lpOutputString  )
 	#define GwenUtil_WideStringToFloat( _Str ) wcstof(_Str, NULL)
 
-#elif defined(__linux__)
+#elif defined(__linux__) || defined(__FreeBSD__)
 
 	#define GwenUtil_VSNPrintFSafe( _DstBuf, _DstSize, _MaxCount, _Format, _ArgList ) vsnprintf( _DstBuf, _DstSize, _Format, _ArgList )
 	#define GwenUtil_VSWPrintFSafe( _DstBuf, _SizeInWords, _Format, _ArgList ) vswprintf( _DstBuf, _SizeInWords, _Format, _ArgList )
