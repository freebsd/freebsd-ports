--- config.m4.orig	Tue Jan 17 15:32:03 2006
+++ config.m4	Tue Jan 17 15:33:12 2006
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
   PHP_CHECK_LIBRARY(history, add_history,
   [
     PHP_ADD_LIBRARY_WITH_PATH(history, $READLINE_DIR/$PHP_LIBDIR, READLINE_SHARED_LIBADD)
@@ -96,7 +101,6 @@
 fi
 
 if test "$PHP_READLINE" != "no" || test "$PHP_LIBEDIT" != "no"; then
-  AC_CHECK_FUNCS([rl_completion_matches])
   PHP_NEW_EXTENSION(readline, readline.c, $ext_shared, cli)
   PHP_SUBST(READLINE_SHARED_LIBADD)
 fi
