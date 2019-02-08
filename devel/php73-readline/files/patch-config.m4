--- config.m4.orig	2019-02-05 13:10:04 UTC
+++ config.m4
@@ -3,13 +3,8 @@ dnl config.m4 for extension readline
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
@@ -72,6 +67,13 @@ if test "$PHP_READLINE" && test "$PHP_RE
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
