--- ./src/compat/LzmaCompatDecode.h.orig	2010-04-24 00:26:40.000000000 +0200
+++ ./src/compat/LzmaCompatDecode.h	2010-11-11 00:20:51.000000000 +0100
@@ -39,14 +39,6 @@
 #  define LZMACALL
 #endif
 
-#ifndef malloc
-# ifdef __APPLE__
-#include <malloc/malloc.h>
-# else
-#include <malloc.h>
-# endif
-#endif
-
 #ifndef UInt32
 #ifdef _LZMA_UINT32_IS_ULONG
 #define UInt32 unsigned long
