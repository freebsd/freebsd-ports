--- src/ftp_listener.c.orig	Wed Apr 18 23:42:48 2001
+++ src/ftp_listener.c	Sun Apr 22 14:26:41 2001
@@ -361,7 +361,7 @@
          if (fd >= 0) {
              
              tcp_nodelay = 1;
-             if (setsockopt(fd, SOL_TCP, TCP_NODELAY, (void *)&tcp_nodelay,
+             if (setsockopt(fd, IPPROTO_TCP, TCP_NODELAY, (void *)&tcp_nodelay,
                  sizeof(int)) != 0)
              {
                  syslog(LOG_ERR,
