--- src/ftp_session.c.orig	Wed Apr 18 23:43:37 2001
+++ src/ftp_session.c	Mon Apr 23 00:38:15 2001
@@ -3,13 +3,13 @@
  */
 
 #include <config.h>
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <string.h>
 #include <stdio.h>
 #include <stdarg.h>
 #include <sys/stat.h>
 #include <unistd.h>
-#include <sys/types.h>
 #include <fcntl.h>
 #include <sys/socket.h>
 #include <errno.h>
@@ -1130,7 +1130,8 @@
         /* for sendfile(), we still have to use a loop to avoid 
            having our watchdog time us out on large files - it does
            allow us to avoid an extra copy to/from user space */
-#ifdef HAVE_LINUX_SENDFILE
+#ifdef FOO_HAVE_LINUX_SENDFILE
+// This doesn't work yet. I'm working with the author to fix it.
         offset = f->file_offset;
         file_size = stat_buf.st_size - offset;
         while (offset < stat_buf.st_size) {
@@ -1139,11 +1140,14 @@
             if (amt_to_send > 65536) {
                 amt_to_send = 65536;
             }
-            sendfile_ret = sendfile(socket_fd, 
-                                    file_fd, 
-                                    &offset, 
-                                    amt_to_send);
-            if (sendfile_ret != amt_to_send) {
+            sendfile_ret = sendfile(file_fd,
+                                    socket_fd, 
+                                    offset,
+                                    amt_to_send,
+                                    NULL,
+                                    NULL,
+                                    0);
+            if (sendfile_ret != 0) {
                 reply(f, 550, "Error sending file; %s.", strerror(errno));
                 goto exit_retr;
             }
