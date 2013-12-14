--- acinclude.m4.orig	2013-12-10 19:32:43.000000000 +0000
+++ acinclude.m4	2013-12-13 21:55:53.955235854 +0000
@@ -984,15 +984,9 @@ dnl ------------------------------------
   if test "$3" != "shared" && test "$3" != "yes" && test "$4" = "cli"; then
 dnl ---------------------------------------------- CLI static module
     [PHP_]translit($1,a-z_-,A-Z__)[_SHARED]=no
-    case "$PHP_SAPI" in
-      cgi|embed[)]
-        PHP_ADD_SOURCES(PHP_EXT_DIR($1),$2,$ac_extra,)
-        EXT_STATIC="$EXT_STATIC $1"
-        ;;
-      *[)]
         PHP_ADD_SOURCES(PHP_EXT_DIR($1),$2,$ac_extra,cli)
-        ;;
-    esac
+        PHP_ADD_SOURCES(PHP_EXT_DIR($1),$2,$ac_extra,cgi)
+        PHP_ADD_SOURCES(PHP_EXT_DIR($1),$2,$ac_extra,fpm)
     EXT_CLI_STATIC="$EXT_CLI_STATIC $1"
   fi
   PHP_ADD_BUILD_DIR($ext_builddir)
@@ -1042,12 +1036,6 @@ You either need to build $1 shared or bu
 build to be successful.
 ])
   fi
-  if test "x$is_it_enabled" = "xno" && test "x$3" != "xtrue"; then
-    AC_MSG_ERROR([
-You've configured extension $1, which depends on extension $2,
-but you've either not enabled $2, or have disabled it.
-])
-  fi
   dnl Some systems require that we link $2 to $1 when building
 ])
 
@@ -2320,9 +2308,9 @@ AC_DEFUN([PHP_SETUP_OPENSSL],[
   test -z "$PHP_IMAP_SSL" && PHP_IMAP_SSL=no
 
   dnl Fallbacks for different configure options
-  if test "$PHP_OPENSSL" != "no"; then
+  if test -n "$PHP_OPENSSL" && test "$PHP_OPENSSL" != "no"; then
     PHP_OPENSSL_DIR=$PHP_OPENSSL
-  elif test "$PHP_IMAP_SSL" != "no"; then
+  elif test -n "$PHP_IMAP_SSL" && test "$PHP_IMAP_SSL" != "no"; then
     PHP_OPENSSL_DIR=$PHP_IMAP_SSL
   fi
 
