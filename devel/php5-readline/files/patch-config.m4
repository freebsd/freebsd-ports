--- config.m4.orig	2009-05-14 15:43:52.000000000 +0200
+++ config.m4	2009-06-26 08:10:39.000000000 +0200
@@ -5,10 +5,8 @@
 PHP_ARG_WITH(libedit,for libedit readline replacement, 
 [  --with-libedit[=DIR]    Include libedit readline replacement (CLI/CGI only)])
 
-if test "$PHP_LIBEDIT" = "no"; then
   PHP_ARG_WITH(readline,for readline support,
   [  --with-readline[=DIR]   Include readline support (CLI/CGI only)])
-fi
 
 if test "$PHP_READLINE" && test "$PHP_READLINE" != "no"; then
   for i in $PHP_READLINE /usr/local /usr; do
@@ -50,6 +48,13 @@
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
@@ -87,7 +92,6 @@
 fi
 
 if test "$PHP_READLINE" != "no" || test "$PHP_LIBEDIT" != "no"; then
-  AC_CHECK_FUNCS([rl_completion_matches])
   PHP_NEW_EXTENSION(readline, readline.c, $ext_shared, cli)
   PHP_SUBST(READLINE_SHARED_LIBADD)
 fi
