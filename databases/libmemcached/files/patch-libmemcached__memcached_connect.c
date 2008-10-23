--- libmemcached/memcached_connect.c.orig	2008-10-23 06:19:25.000000000 -0700
+++ libmemcached/memcached_connect.c	2008-10-23 06:23:16.000000000 -0700
@@ -225,6 +225,7 @@
           {
             struct pollfd fds[1];
             int error;
+            socklen_t len;
 
             memset(&fds, 0, sizeof(struct pollfd));
             fds[0].fd= ptr->fd;
@@ -237,6 +238,7 @@
             }
             else if (error != 1 || fds[0].revents & POLLERR)
             {
+closesock:
               ptr->cached_errno= errno;
               WATCHPOINT_ERRNO(ptr->cached_errno);
               WATCHPOINT_NUMBER(ptr->root->connect_timeout);
@@ -259,6 +261,13 @@
               return MEMCACHED_ERRNO;
             }
 
+            len = sizeof (error);
+            if (getsockopt (ptr->fd, SOL_SOCKET, SO_ERROR, &error, &len) < 0)
+              goto closesock;
+
+            if (error > 0)
+              goto closesock;
+
             break;
           }
         /* We are spinning waiting on connect */
