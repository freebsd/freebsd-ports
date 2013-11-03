--- base/compiler_specific.h.orig	2013-07-17 11:38:04.000000000 +0900
+++ base/compiler_specific.h	2013-11-03 21:42:23.000000000 +0900
@@ -236,4 +236,8 @@
 #endif  // _MSC_VER or !_MSC_VER
 // === End suppress warning C4355 macro definitions ===
 
+#ifndef static_assert
+#define	static_assert(a,b)
+#endif
+
 #endif  // MOZC_BASE_COMPILER_SPECIFIC_H
