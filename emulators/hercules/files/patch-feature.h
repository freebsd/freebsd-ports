--- feature.h.orig	Mon Sep  2 11:36:09 2002
+++ feature.h	Mon Sep  2 11:36:55 2002
@@ -479,4 +479,9 @@
  #define XSTORE_PAGEMASK	0x7FFFF000
 #endif
 
+#if defined(__FreeBSD__)
+ #define HAVE_MTIO_H
+#else
+ #define GNU_MTIO_SUPPORT
+#endif
 /* end of FEATURES.H */
