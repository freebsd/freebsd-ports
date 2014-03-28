Fix the inheritance of the non-blocking option across apr_socket_accept()
on FreeBSD 10 which was introduced with APR 1.5.0 through an unlikely
mechanism:

* FreeBSD 10 introduced accept4().  APR uses accept4() where it can find it.
  accept4() on Linux and FreeBSD 10 both have a SOCK_NONBLOCK flag, but on
  FreeBSD 10 the SOCK_NONBLOCK is the sole determiner of whether or not the
  connected socket is non-blocking.
* clang is normally used on FreeBSD 10.
* APR's configure-time check for inherited O_NONBLOCK didn't work with clang,
  so initially the lack of inheritance across accept4() wasn't a problem.
* APR 1.5.0 allowed the configure-time check to work with clang, exposing
  the bad expectation about accept4() matching the accept() behavior.

With FreeBSD accept4() (avail in 10+), O_NONBLOCK is not inherited
(unlike Linux).  Mimic the accept() behavior here in a way that
may help other platforms as well.

http://svn.apache.org/viewvc?view=revision&revision=1551672
===================================================================================
--- ./apr-1.5.0/network_io/unix/sockets.c.orig	2011-03-23 19:50:21.000000000 +0100
+++ ./apr-1.5.0/network_io/unix/sockets.c	2014-03-22 18:52:57.000000000 +0100
@@ -207,7 +207,20 @@
     sa.salen = sizeof(sa.sa);
 
 #ifdef HAVE_ACCEPT4
-    s = accept4(sock->socketdes, (struct sockaddr *)&sa.sa, &sa.salen, SOCK_CLOEXEC);
+    {
+        int flags = SOCK_CLOEXEC;
+
+#if defined(SOCK_NONBLOCK) && APR_O_NONBLOCK_INHERITED
+        /* With FreeBSD accept4() (avail in 10+), O_NONBLOCK is not inherited
+         * (unlike Linux).  Mimic the accept() behavior here in a way that
+         * may help other platforms.
+         */
+        if (apr_is_option_set(sock, APR_SO_NONBLOCK) == 1) {
+            flags |= SOCK_NONBLOCK;
+        }
+#endif
+        s = accept4(sock->socketdes, (struct sockaddr *)&sa.sa, &sa.salen, flags);
+    }
 #else
     s = accept(sock->socketdes, (struct sockaddr *)&sa.sa, &sa.salen);
 #endif
