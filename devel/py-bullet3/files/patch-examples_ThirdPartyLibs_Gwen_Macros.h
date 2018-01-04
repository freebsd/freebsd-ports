--- examples/ThirdPartyLibs/Gwen/Macros.h.orig	2017-09-29 23:20:39 UTC
+++ examples/ThirdPartyLibs/Gwen/Macros.h
@@ -40,7 +40,7 @@
 	#define GwenUtil_OutputDebugWideString( lpOutputString ) //wprintf( lpOutputString  )
 	#define GwenUtil_WideStringToFloat( _Str ) wcstof(_Str, NULL)
 
-#elif defined(__linux__) || defined(__OpenBSD__)
+#elif defined(__linux__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 
 	#define GwenUtil_VSNPrintFSafe( _DstBuf, _DstSize, _MaxCount, _Format, _ArgList ) vsnprintf( _DstBuf, _DstSize, _Format, _ArgList )
 	#define GwenUtil_VSWPrintFSafe( _DstBuf, _SizeInWords, _Format, _ArgList ) vswprintf( _DstBuf, _SizeInWords, _Format, _ArgList )
