--- ./plugins/core/qRANSAC_SD/RANSAC_SD_orig/MiscLib/AlignedAllocator.h.orig	2019-01-07 13:59:17.670295000 -0500
+++ ./plugins/core/qRANSAC_SD/RANSAC_SD_orig/MiscLib/AlignedAllocator.h	2019-01-07 13:59:38.242600000 -0500
@@ -1,7 +1,7 @@
 #ifndef MiscLib__ALIGNEDALLOCATOR_HEADER__
 #define MiscLib__ALIGNEDALLOCATOR_HEADER__
 #include <memory>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #else
 #include <stdlib.h>
