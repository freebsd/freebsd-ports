--- ./plugins/core/qRANSAC_SD/RANSAC_SD_orig/GfxTL/FlatCopyVector.h.orig	2019-01-07 13:54:30.016129000 -0500
+++ ./plugins/core/qRANSAC_SD/RANSAC_SD_orig/GfxTL/FlatCopyVector.h	2019-01-07 13:55:05.855728000 -0500
@@ -1,6 +1,6 @@
 #ifndef GfxTL__FLATCOPYVECTOR_HEADER__
 #define GfxTL__FLATCOPYVECTOR_HEADER__
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #else
 #include <stdlib.h>
