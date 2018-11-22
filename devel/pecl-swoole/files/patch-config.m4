--- config.m4.orig	2018-11-19 09:43:54 UTC
+++ config.m4
@@ -372,7 +372,7 @@ if test "$PHP_SWOOLE" != "no"; then
     AC_CHECK_LIB(c, poll, AC_DEFINE(HAVE_POLL, 1, [have poll]))
     AC_CHECK_LIB(c, sendfile, AC_DEFINE(HAVE_SENDFILE, 1, [have sendfile]))
     AC_CHECK_LIB(c, kqueue, AC_DEFINE(HAVE_KQUEUE, 1, [have kqueue]))
-    AC_CHECK_LIB(c, backtrace, AC_DEFINE(HAVE_EXECINFO, 1, [have execinfo]))
+    AC_CHECK_LIB(execinfo, backtrace, AC_DEFINE(HAVE_EXECINFO, 1, [have execinfo]))
     AC_CHECK_LIB(c, daemon, AC_DEFINE(HAVE_DAEMON, 1, [have daemon]))
     AC_CHECK_LIB(c, mkostemp, AC_DEFINE(HAVE_MKOSTEMP, 1, [have mkostemp]))
     AC_CHECK_LIB(c, inotify_init, AC_DEFINE(HAVE_INOTIFY, 1, [have inotify]))
@@ -608,7 +608,7 @@ if test "$PHP_SWOOLE" != "no"; then
     PHP_INSTALL_HEADERS([ext/swoole], [*.h config.h include/*.h])
 
     PHP_REQUIRE_CXX()
-    PHP_ADD_LIBRARY(stdc++, 1, SWOOLE_SHARED_LIBADD)
+    PHP_ADD_LIBRARY(c++, 1, SWOOLE_SHARED_LIBADD)
     CXXFLAGS="$CXXFLAGS -Wall -Wno-unused-function -Wno-deprecated -Wno-deprecated-declarations -std=c++11"
 
     if test "$PHP_PICOHTTPPARSER" = "yes"; then
