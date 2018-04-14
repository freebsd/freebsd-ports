--- plugins/qRANSAC_SD/RANSAC_SD_orig/GfxTL/FlatCopyVector.h.orig	2018-04-14 01:45:59 UTC
+++ plugins/qRANSAC_SD/RANSAC_SD_orig/GfxTL/FlatCopyVector.h
@@ -1,6 +1,6 @@
 #ifndef GfxTL__FLATCOPYVECTOR_HEADER__
 #define GfxTL__FLATCOPYVECTOR_HEADER__
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #else
 #include <stdlib.h>
