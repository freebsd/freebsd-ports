--- common/plugins/resamplers/helpers.h.orig	Sun Oct 26 04:16:26 2003
+++ common/plugins/resamplers/helpers.h	Thu Oct 30 12:02:04 2003
@@ -17,6 +17,11 @@
 #define HELPERS_H
 
 
+#if defined(__FreeBSD__)
+  #define lrint(flt)	((int) (flt))
+  #define lrintf(flt)	((int) (flt))
+#endif
+
 //hardcoded for now!
 #define FILTER_BITS 12
 #define RAMP_BITS 11
