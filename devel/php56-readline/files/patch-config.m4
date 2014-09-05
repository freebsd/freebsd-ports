--- config.m4.orig	2013-08-20 06:46:43.000000000 +0200
+++ config.m4	2013-08-27 16:01:29.000000000 +0200
@@ -5,13 +5,8 @@
 PHP_ARG_WITH(libedit,for libedit readline replacement, 
 [  --with-libedit[=DIR]      Include libedit readline replacement (CLI/CGI only)])
 
-if test "$PHP_LIBEDIT" = "no"; then
   PHP_ARG_WITH(readline,for readline support,
   [  --with-readline[=DIR]     Include readline support (CLI/CGI only)])
-else
-  dnl "register" the --with-readline option to preven invalid "unknown configure option" warning
-  php_with_readline=no
-fi
 
 if test "$PHP_READLINE" && test "$PHP_READLINE" != "no"; then
   for i in $PHP_READLINE /usr/local /usr; do
@@ -67,6 +62,13 @@
     -L$READLINE_DIR/$PHP_LIBDIR $PHP_READLINE_LIBS
   ])
 
+  PHP_CHECK_LIBRARY(readline, rl_completion_matches,
+  [
+    AC_DEFINE(HAVE_RL_COMPLETION_MATCHES, 1, [ ])
+  ],[],[
+    -L$READLINE_DIR/$PHP_LIBDIR $PHP_READLINE_LIBS
+  ])
+
   AC_DEFINE(HAVE_LIBREADLINE, 1, [ ])
 
 elif test "$PHP_LIBEDIT" != "no"; then
@@ -118,7 +120,6 @@
 fi
 
 if test "$PHP_READLINE" != "no" || test "$PHP_LIBEDIT" != "no"; then
-  AC_CHECK_FUNCS([rl_completion_matches])
   PHP_NEW_EXTENSION(readline, readline.c readline_cli.c, $ext_shared, cli)
   PHP_SUBST(READLINE_SHARED_LIBADD)
 fi
