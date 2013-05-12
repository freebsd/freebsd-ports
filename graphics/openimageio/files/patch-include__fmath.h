--- include/fmath.h.orig	2013-01-21 11:39:43.845857535 +1030
+++ include/fmath.h	2013-01-21 11:39:52.142857433 +1030
@@ -976,7 +976,7 @@
 
 
 // Functions missing from FreeBSD
-#if (defined(__FreeBSD__) && (__FreeBSD_version < 803000))
+#if (defined(__FreeBSD__) && (__FreeBSD_version < 802502))
 
 inline float
 log2f (float val) {
