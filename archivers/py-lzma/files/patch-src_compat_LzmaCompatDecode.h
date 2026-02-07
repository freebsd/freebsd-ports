--- src/compat/LzmaCompatDecode.h.orig	2016-07-26 12:20:39 UTC
+++ src/compat/LzmaCompatDecode.h
@@ -39,14 +39,6 @@ extern "C" {
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
