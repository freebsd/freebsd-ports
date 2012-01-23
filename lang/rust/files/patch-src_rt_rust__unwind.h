--- src/rt/rust_unwind.h.orig	2012-01-22 08:58:11.386020911 +0800
+++ src/rt/rust_unwind.h	2012-01-22 04:37:29.745804340 +0800
@@ -17,6 +17,8 @@
 
 #if (defined __APPLE__) || (defined __clang__)
 
+#ifndef __FreeBSD__
+
 typedef int _Unwind_Action;
 typedef void _Unwind_Exception;
 
@@ -24,3 +26,5 @@
 
 #endif
 
+#endif
+
