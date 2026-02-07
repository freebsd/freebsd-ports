--- libgamin/gam_fork.h.orig	2007-07-04 06:36:48.000000000 -0700
+++ libgamin/gam_fork.h	2013-02-16 20:38:00.328594608 -0800
@@ -32,6 +32,9 @@
 #endif
 
 int		gamin_fork_server	(const char *fam_client_id);
+#ifdef RUN_AS_EUID
+int		gamin_drop_privileges	(int to_uid, int to_gid);
+#endif
 
 #ifdef __cplusplus
 }
