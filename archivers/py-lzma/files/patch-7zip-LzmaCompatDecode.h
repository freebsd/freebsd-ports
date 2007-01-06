--- 7zip/LzmaCompatDecode.h.orig	Thu Dec 28 06:27:50 2006
+++ 7zip/LzmaCompatDecode.h	Thu Dec 28 06:27:56 2006
@@ -39,10 +39,6 @@
 #  define LZMACALL
 #endif
 
-#ifndef malloc
-#include <malloc.h>
-#endif
-
 #ifndef UInt32
 #ifdef _LZMA_UINT32_IS_ULONG
 #define UInt32 unsigned long
