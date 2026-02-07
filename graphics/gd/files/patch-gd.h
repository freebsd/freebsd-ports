--- src/gd.h.orig	2021-09-11 04:52:47 UTC
+++ src/gd.h
@@ -1604,6 +1604,11 @@ BGD_DECLARE(void) gdImageFlipHorizontal(gdImagePtr im)
 BGD_DECLARE(void) gdImageFlipVertical(gdImagePtr im);
 BGD_DECLARE(void) gdImageFlipBoth(gdImagePtr im);
 
+#define GD_FLIP_HORINZONTAL 1 /* typo, kept for BC */
+#define GD_FLIP_HORIZONTAL 1
+#define GD_FLIP_VERTICAL 2
+#define GD_FLIP_BOTH 3
+
 /**
  * Group: Crop
  *
