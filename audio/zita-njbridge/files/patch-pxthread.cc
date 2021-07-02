--- pxthread.cc.orig	2021-07-02 16:43:47 UTC
+++ pxthread.cc
@@ -25,7 +25,7 @@
 // ----------------------------------------------------------------------------
 
 
-#if defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__GNU__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__GNU__) || defined(__APPLE__) || defined(__FreeBSD__)
 
 
 Pxthread::Pxthread (void)
