--- acinclude.m4.orig	Mon Dec 19 23:29:11 2005
+++ acinclude.m4	Fri May  5 08:05:43 2006
@@ -84,7 +84,7 @@
 dnl
 dnl which array to append to?
 AC_DEFUN([PHP_ADD_SOURCES],[
-  PHP_ADD_SOURCES_X($1, $2, $3, ifelse($4,cli,PHP_CLI_OBJS,ifelse($4,sapi,PHP_SAPI_OBJS,PHP_GLOBAL_OBJS)))
+  PHP_ADD_SOURCES_X($1, $2, $3, ifelse($4,cli,PHP_CLI_OBJS,ifelse($4,sapi,PHP_SAPI_OBJS,ifelse($4,cgi,PHP_CGI_OBJS,PHP_GLOBAL_OBJS))))
 ])
 dnl
 dnl _PHP_ASSIGN_BUILD_VARS(type)
@@ -1305,12 +1305,8 @@
 
   if test "$3" != "shared" && test "$3" != "yes" && test "$4" = "cli"; then
 dnl ---------------------------------------------- CLI static module
-    if test "$PHP_SAPI" = "cgi"; then
-      PHP_ADD_SOURCES(PHP_EXT_DIR($1),$2,$ac_extra,)
-      EXT_STATIC="$EXT_STATIC $1"
-    else
       PHP_ADD_SOURCES(PHP_EXT_DIR($1),$2,$ac_extra,cli)
-    fi
+      PHP_ADD_SOURCES(PHP_EXT_DIR($1),$2,$ac_extra,cgi)
     EXT_CLI_STATIC="$EXT_CLI_STATIC $1"
   fi
   PHP_ADD_BUILD_DIR($ext_builddir)
@@ -1713,9 +1709,9 @@
   test -z "$PHP_IMAP_SSL" && PHP_IMAP_SSL=no
 
   dnl Fallbacks for different configure options
-  if test "$PHP_OPENSSL" != "no"; then
+  if test -n "$PHP_OPENSSL" && test "$PHP_OPENSSL" != "no"; then
     PHP_OPENSSL_DIR=$PHP_OPENSSL
-  elif test "$PHP_IMAP_SSL" != "no"; then
+  elif test -n "$PHP_IMAP_SSL" && test "$PHP_IMAP_SSL" != "no"; then
     PHP_OPENSSL_DIR=$PHP_IMAP_SSL
   fi
 
