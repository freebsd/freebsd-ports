--- sql/mylibwrap.h.orig	Thu Jan  1 01:00:00 1970
+++ sql/mylibwrap.h		Sun Sep 19 15:04:21 2004
@@ -0,0 +1,9 @@
+#ifdef __cplusplus
+extern "C" {
+#endif
+extern void my_fromhost(struct request_info *);
+extern int my_hosts_access(struct request_info *);
+extern char *my_eval_client(struct request_info *);
+#ifdef __cplusplus
+}
+#endif
