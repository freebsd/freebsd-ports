--- src/hqx/common.h.orig	2014-10-03 16:27:22 UTC
+++ src/hqx/common.h
@@ -50,9 +50,9 @@ static inline uint32_t rgb_to_yuv(uint32
 
 /* Test if there is difference in color */
 static inline int yuv_diff(uint32_t yuv1, uint32_t yuv2) {
-    return (( abs((yuv1 & Ymask) - (yuv2 & Ymask)) > trY ) ||
-            ( abs((yuv1 & Umask) - (yuv2 & Umask)) > trU ) ||
-            ( abs((yuv1 & Vmask) - (yuv2 & Vmask)) > trV ) );
+    return (( abs((int)(yuv1 & Ymask) - (int)(yuv2 & Ymask)) > trY ) ||
+            ( abs((int)(yuv1 & Umask) - (int)(yuv2 & Umask)) > trU ) ||
+            ( abs((int)(yuv1 & Vmask) - (int)(yuv2 & Vmask)) > trV ) );
 }
 
 static inline int Diff(uint32_t c1, uint32_t c2)
