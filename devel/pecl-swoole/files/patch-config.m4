--- config.m4.orig	2017-01-24 02:05:48 UTC
+++ config.m4
@@ -85,7 +85,13 @@ AC_DEFUN([AC_SWOOLE_CPU_AFFINITY],
     AC_MSG_CHECKING([for cpu affinity])
     AC_TRY_COMPILE(
     [
+		#ifdef __FreeBSD__
+		#include <sys/types.h>
+		#include <sys/cpuset.h>
+		typedef cpuset_t cpu_set_t;
+		#else
 		#include <sched.h>
+		#endif
     ], [
 		cpu_set_t cpu_set;
 		CPU_ZERO(&cpu_set);
@@ -178,7 +184,7 @@ if test "$PHP_SWOOLE" != "no"; then
     AC_CHECK_LIB(c, poll, AC_DEFINE(HAVE_POLL, 1, [have poll]))
     AC_CHECK_LIB(c, sendfile, AC_DEFINE(HAVE_SENDFILE, 1, [have sendfile]))
     AC_CHECK_LIB(c, kqueue, AC_DEFINE(HAVE_KQUEUE, 1, [have kqueue]))
-    AC_CHECK_LIB(c, backtrace, AC_DEFINE(HAVE_EXECINFO, 1, [have execinfo]))
+    AC_CHECK_LIB(execinfo, backtrace, AC_DEFINE(HAVE_EXECINFO, 1, [have execinfo]))
     AC_CHECK_LIB(c, daemon, AC_DEFINE(HAVE_DAEMON, 1, [have daemon]))
     AC_CHECK_LIB(c, mkostemp, AC_DEFINE(HAVE_MKOSTEMP, 1, [have mkostemp]))
     AC_CHECK_LIB(c, inotify_init, AC_DEFINE(HAVE_INOTIFY, 1, [have inotify]))
