--- lib/intel_batchbuffer.c.orig	2022-08-31 20:00:01 UTC
+++ lib/intel_batchbuffer.c
@@ -60,6 +60,11 @@
 #define BCS_SRC_Y (1 << 0)
 #define BCS_DST_Y (1 << 1)
 
+/* memory leak */
+#ifdef __FreeBSD__
+#define	tdestroy(root, free_node)
+#endif
+
 /**
  * SECTION:intel_batchbuffer
  * @short_description: Batchbuffer and blitter support
