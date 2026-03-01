--- client/gvfsfusedaemon.c.orig	2024-10-18 10:28:21 UTC
+++ client/gvfsfusedaemon.c
@@ -2478,7 +2478,9 @@ vfs_init (struct fuse_conn_info *conn, struct fuse_con
   subthread = g_thread_new ("gvfs-fuse-sub", (GThreadFunc) subthread_main, NULL);
 
   /* Indicate O_TRUNC support for open() */
+#ifdef FUSE_CAP_ATOMIC_O_TRUNC
   conn->want |= FUSE_CAP_ATOMIC_O_TRUNC;
+#endif
 
   /* Prevent out-of-order readahead */
   conn->want &= ~FUSE_CAP_ASYNC_READ;
