--- glibtop.h.orig	2015-08-13 19:30:44.824882000 +0200
+++ glibtop.h	2015-08-13 19:30:04.376611000 +0200
@@ -125,14 +125,35 @@ extern glibtop *glibtop_global_server;
 
 extern const unsigned long glibtop_server_features;
 
+/**
+ * glibtop_init:
+ *
+ * Returns: (transfer none):
+ */
 glibtop *
 glibtop_init (void);
 
+/**
+ * glibtop_init_r:
+ * @server_ptr: (out):
+ * @features:
+ * @flags:
+ *
+ * Returns: (transfer none):
+ */
 glibtop *
 glibtop_init_r (glibtop **server_ptr,
 		unsigned long features,
 		unsigned flags);
 
+/**
+ * glibtop_init_s:
+ * @server_ptr: (out):
+ * @features:
+ * @flags:
+ *
+ * Returns: (transfer none):
+ */
 glibtop *
 glibtop_init_s (glibtop **server_ptr,
 		unsigned long features,
