--- config.m4.orig	Wed Nov 30 05:50:03 2005
+++ config.m4	Tue Jan 17 12:51:21 2006
@@ -48,14 +48,6 @@
 
 
 if test "$PHP_SQLITE" != "no"; then
-  if test "$PHP_PDO" != "no"; then
-    PHP_CHECK_PDO_INCLUDES([], [AC_MSG_WARN([Cannot find php_pdo_driver.h.])])
-    if test -n "$pdo_inc_path"; then
-      AC_DEFINE([PHP_SQLITE2_HAVE_PDO], [1], [Have PDO])
-      pdo_inc_path="-I$pdo_inc_path"
-    fi
-  fi  
-
   if test "$PHP_SQLITE" != "yes"; then
     SEARCH_PATH="/usr/local /usr"
     SEARCH_FOR="/include/sqlite.h"
@@ -85,13 +77,12 @@
       -L$SQLITE_DIR/$PHP_LIBDIR -lm
     ])
     SQLITE_MODULE_TYPE=external
-    PHP_SQLITE_CFLAGS=$pdo_inc_path
     sqlite_extra_sources="libsqlite/src/encode.c"
   else
     # use bundled library
     PHP_PROG_LEMON
     SQLITE_MODULE_TYPE=builtin
-    PHP_SQLITE_CFLAGS="-I@ext_srcdir@/libsqlite/src -I@ext_builddir@/libsqlite/src $pdo_inc_path"
+    PHP_SQLITE_CFLAGS="-I@ext_srcdir@/libsqlite/src -I@ext_builddir@/libsqlite/src"
     sqlite_extra_sources="libsqlite/src/opcodes.c \
         libsqlite/src/parse.c libsqlite/src/encode.c \
         libsqlite/src/auth.c libsqlite/src/btree.c libsqlite/src/build.c \
@@ -109,10 +100,9 @@
   dnl
   dnl Common for both bundled/external
   dnl
-  sqlite_sources="sqlite.c sess_sqlite.c pdo_sqlite2.c $sqlite_extra_sources" 
+  sqlite_sources="sqlite.c sess_sqlite.c $sqlite_extra_sources" 
   PHP_NEW_EXTENSION(sqlite, $sqlite_sources, $ext_shared,,$PHP_SQLITE_CFLAGS)
   PHP_ADD_EXTENSION_DEP(sqlite, spl, true)
-  PHP_ADD_EXTENSION_DEP(sqlite, pdo, true)
 
   PHP_ADD_MAKEFILE_FRAGMENT
   PHP_SUBST(SQLITE_SHARED_LIBADD)
