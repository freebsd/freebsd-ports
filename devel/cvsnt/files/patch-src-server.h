--- src/server.h.orig	Fri Jan 23 18:51:00 2004
+++ src/server.h	Fri Jan 23 18:54:13 2004
@@ -91,7 +91,13 @@
 struct buffer;
 #endif
 
-extern void server_updated();
+extern void server_updated(
+    struct file_info *finfo,
+    Vers_TS *vers,
+    enum server_updated_arg4 updated,
+    mode_t mode,
+    unsigned char *checksum,
+    struct buffer *filebuf);
 
 /* Whether we should send RCS format patches.  */
 extern int server_use_rcs_diff();
