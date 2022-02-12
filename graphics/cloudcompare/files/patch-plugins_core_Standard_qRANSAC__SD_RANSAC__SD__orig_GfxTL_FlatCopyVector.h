--- plugins/core/Standard/qRANSAC_SD/RANSAC_SD_orig/GfxTL/FlatCopyVector.h.orig	2020-09-08 09:36:07 UTC
+++ plugins/core/Standard/qRANSAC_SD/RANSAC_SD_orig/GfxTL/FlatCopyVector.h
@@ -1,6 +1,6 @@
 #ifndef GfxTL__FLATCOPYVECTOR_HEADER__
 #define GfxTL__FLATCOPYVECTOR_HEADER__
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #else
 #include <stdlib.h>
