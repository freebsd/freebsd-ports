--- src/ftp_session.c.orig	Sun Jun 17 03:45:08 2001
+++ src/ftp_session.c	Sun Jun 17 03:46:26 2001
@@ -1165,7 +1165,7 @@
         /* for sendfile(), we still have to use a loop to avoid 
            having our watchdog time us out on large files - it does
            allow us to avoid an extra copy to/from user space */
-#ifdef HAVE_SENDFILE
+/* #ifdef HAVE_SENDFILE
         offset = f->file_offset;
         file_size = stat_buf.st_size - offset;
         while (offset < stat_buf.st_size) {
@@ -1200,7 +1200,7 @@
 
 	    watchdog_defer_watched(f->watched);
         }
-#else
+#else */
         for (;;) {
             read_ret = read(file_fd, buf, sizeof(buf));
 	    if (read_ret == -1) {
@@ -1219,7 +1219,7 @@
 
 	    watchdog_defer_watched(f->watched);
 	}
-#endif  /* HAVE_SENDFILE */
+/* #endif */ /* HAVE_SENDFILE */
     }
 
     /* disconnect */
