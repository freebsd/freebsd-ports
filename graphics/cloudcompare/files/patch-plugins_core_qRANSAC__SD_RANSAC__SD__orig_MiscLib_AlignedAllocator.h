--- plugins/core/qRANSAC_SD/RANSAC_SD_orig/MiscLib/AlignedAllocator.h.orig	2019-06-13 21:16:40 UTC
+++ plugins/core/qRANSAC_SD/RANSAC_SD_orig/MiscLib/AlignedAllocator.h
@@ -1,12 +1,12 @@
 #ifndef MiscLib__ALIGNEDALLOCATOR_HEADER__
 #define MiscLib__ALIGNEDALLOCATOR_HEADER__
 #include <memory>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #else
 #include <stdlib.h>
 #endif
-#include <xmmintrin.h>
+#include <mm_malloc.h>
 #include <limits>
 #ifdef max
 #undef max
