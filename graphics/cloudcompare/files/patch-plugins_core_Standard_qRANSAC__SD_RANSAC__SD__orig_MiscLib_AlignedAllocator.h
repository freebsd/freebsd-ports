--- plugins/core/Standard/qRANSAC_SD/RANSAC_SD_orig/MiscLib/AlignedAllocator.h.orig	2020-09-08 09:36:07 UTC
+++ plugins/core/Standard/qRANSAC_SD/RANSAC_SD_orig/MiscLib/AlignedAllocator.h
@@ -1,7 +1,7 @@
 #ifndef MiscLib__ALIGNEDALLOCATOR_HEADER__
 #define MiscLib__ALIGNEDALLOCATOR_HEADER__
 #include <memory>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #else
 #include <stdlib.h>
@@ -9,6 +9,7 @@
 
 #if defined(__x86_64__) || defined(__i386__) || defined(_M_IX86) || defined(_M_X64)
 #include <xmmintrin.h>
+#include <mm_malloc.h>
 #endif
 
 #ifdef _mm_malloc
