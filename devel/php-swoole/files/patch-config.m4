--- config.m4.orig	2026-09-22 07:57:52 UTC
+++ config.m4
@@ -449,7 +449,7 @@ if test "$PHP_SWOOLE" != "no"; then
     AC_CHECK_LIB(c, epoll_create, AC_DEFINE(HAVE_EPOLL, 1, [have epoll]))
     AC_CHECK_LIB(c, sendfile, AC_DEFINE(HAVE_SENDFILE, 1, [have sendfile]))
     AC_CHECK_LIB(c, kqueue, AC_DEFINE(HAVE_KQUEUE, 1, [have kqueue]))
-    AC_CHECK_LIB(c, backtrace, AC_DEFINE(HAVE_EXECINFO, 1, [have execinfo]))
+    AC_CHECK_LIB(execinfo, backtrace, AC_DEFINE(HAVE_EXECINFO, 1, [have execinfo]))
     AC_CHECK_LIB(c, daemon, AC_DEFINE(HAVE_DAEMON, 1, [have daemon]))
     AC_CHECK_LIB(c, mkostemp, AC_DEFINE(HAVE_MKOSTEMP, 1, [have mkostemp]))
     AC_CHECK_LIB(c, inotify_init, AC_DEFINE(HAVE_INOTIFY, 1, [have inotify]))
