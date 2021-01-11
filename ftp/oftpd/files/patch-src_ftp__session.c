--- src/ftp_session.c.orig	2004-03-25 20:46:40 UTC
+++ src/ftp_session.c
@@ -1165,7 +1165,7 @@ static void do_retr(ftp_session_t *f, const ftp_comman
         /* for sendfile(), we still have to use a loop to avoid 
            having our watchdog time us out on large files - it does
            allow us to avoid an extra copy to/from user space */
-#ifdef HAVE_SENDFILE
+/* #ifdef HAVE_SENDFILE
         offset = f->file_offset;
         file_size = stat_buf.st_size - offset;
         while (offset < stat_buf.st_size) {
@@ -1200,7 +1200,7 @@ static void do_retr(ftp_session_t *f, const ftp_comman
 
 	    watchdog_defer_watched(f->watched);
         }
-#else
+#else */
         for (;;) {
             read_ret = read(file_fd, buf, sizeof(buf));
 	    if (read_ret == -1) {
@@ -1219,7 +1219,7 @@ static void do_retr(ftp_session_t *f, const ftp_comman
 
 	    watchdog_defer_watched(f->watched);
 	}
-#endif  /* HAVE_SENDFILE */
+/* #endif */ /* HAVE_SENDFILE */
     }
 
     /* disconnect */
