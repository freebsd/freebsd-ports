--- ./plugins/core/qRANSAC_SD/RANSAC_SD_orig/GfxTL/KdTree.h.orig	2019-01-07 13:56:42.017699000 -0500
+++ ./plugins/core/qRANSAC_SD/RANSAC_SD_orig/GfxTL/KdTree.h	2019-01-07 13:57:21.280897000 -0500
@@ -14,7 +14,7 @@
 #include <algorithm>
 #include <memory>
 #include <deque>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #else
 #include <stdlib.h>
