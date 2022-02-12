--- plugins/core/Standard/qRANSAC_SD/RANSAC_SD_orig/GfxTL/KdTree.h.orig	2020-09-08 09:36:07 UTC
+++ plugins/core/Standard/qRANSAC_SD/RANSAC_SD_orig/GfxTL/KdTree.h
@@ -14,7 +14,7 @@
 #include <algorithm>
 #include <memory>
 #include <deque>
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
 #include <malloc.h>
 #else
 #include <stdlib.h>
