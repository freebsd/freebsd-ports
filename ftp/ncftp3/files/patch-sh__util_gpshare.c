--- sh_util/gpshare.c.orig	2016-11-12 23:53:39 UTC
+++ sh_util/gpshare.c
@@ -28,7 +28,7 @@
 
 static int gIsAtty1 = 1, gIsAtty2 = 1;
 extern int gLoadedBm, gBookmarkMatchMode;
-Bookmark gBm;
+extern Bookmark gBm;
 
 double
 FileSize(double size, const char **uStr0, double *uMult0)
