--- base/compiler_specific.h.orig	2013-07-17 11:38:04.000000000 +0900
+++ base/compiler_specific.h	2013-07-20 00:41:09.000000000 +0900
@@ -236,4 +236,10 @@
 #endif  // _MSC_VER or !_MSC_VER
 // === End suppress warning C4355 macro definitions ===
 
+#if 0
+#define	static_assert(a,b) { char _dum[(a) ? 1 : 0]; }
+#endif
+#define	static_assert(a,b)
+#define	unique_ptr auto_ptr
+
 #endif  // MOZC_BASE_COMPILER_SPECIFIC_H
