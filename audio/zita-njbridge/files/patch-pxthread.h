--- pxthread.h.orig	2021-07-02 16:38:46 UTC
+++ pxthread.h
@@ -25,7 +25,7 @@
 // ----------------------------------------------------------------------------
 
 
-#if defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__GNU__) || defined(__APPLE__)
+#if defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__GNU__) || defined(__APPLE__) || defined(__FreeBSD__)
 
 // NOTE: __FreeBSD_kernel__  and __GNU__ were added by the Debian maintainers
 // (the latter for the HURD version of Debian). Things are reported to work
@@ -61,7 +61,7 @@ class Pxthread (private)
 // ----------------------------------------------------------------------------
 
 
-#if defined(__linux__) || defined(__FreeBSD_kernel__) || defined(__GNU__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__GNU__)
 
 class Pxsema
 {
