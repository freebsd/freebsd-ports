--- plugins/qRANSAC_SD/RANSAC_SD_orig/MiscLib/AlignedAllocator.h.orig	2018-04-14 01:44:24 UTC
+++ plugins/qRANSAC_SD/RANSAC_SD_orig/MiscLib/AlignedAllocator.h
@@ -1,7 +1,7 @@
 #ifndef MiscLib__ALIGNEDALLOCATOR_HEADER__
 #define MiscLib__ALIGNEDALLOCATOR_HEADER__
 #include <memory>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #else
 #include <stdlib.h>
