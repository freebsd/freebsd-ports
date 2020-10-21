--- config.m4.orig	2019-08-06 06:54:14 UTC
+++ config.m4
@@ -3,16 +3,10 @@ PHP_ARG_WITH([libedit],
   [AS_HELP_STRING([--with-libedit],
     [Include libedit readline replacement (CLI/CGI only)])])
 
-if test "$PHP_LIBEDIT" = "no"; then
   PHP_ARG_WITH([readline],
     [for readline support],
     [AS_HELP_STRING([[--with-readline[=DIR]]],
       [Include readline support (CLI/CGI only)])])
-else
-  dnl "register" the --with-readline option to prevent invalid "unknown
-  dnl configure option" warning
-  php_with_readline=no
-fi
 
 if test "$PHP_READLINE" && test "$PHP_READLINE" != "no"; then
   for i in $PHP_READLINE /usr/local /usr; do
@@ -78,6 +72,13 @@ if test "$PHP_READLINE" && test "$PHP_RE
   AC_DEFINE(HAVE_HISTORY_LIST, 1, [ ])
   AC_DEFINE(HAVE_LIBREADLINE, 1, [ ])
 
+  PHP_CHECK_LIBRARY(readline, rl_completion_matches,
+  [
+    AC_DEFINE(HAVE_RL_COMPLETION_MATCHES, 1, [ ])
+  ],[],[
+    -L$READLINE_DIR/$PHP_LIBDIR $PHP_READLINE_LIBS
+  ])
+
 elif test "$PHP_LIBEDIT" != "no"; then
   if test "$PHP_LIBEDIT" != "yes"; then
     AC_MSG_WARN([libedit directory ignored, rely on pkg-config])
