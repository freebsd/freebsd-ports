--- ./config.m4.orig	2012-05-04 17:51:20.000000000 +0800
+++ ./config.m4	2013-08-29 12:49:00.000000000 +0800
@@ -1,22 +1,51 @@
 dnl $Id: config.m4 262896 2008-07-17 19:11:16Z lbarnaud $
 dnl config.m4 for extension inotify
 
-PHP_ARG_ENABLE(inotify, whether to enable inotify support,
-[  --enable-inotify        Enable inotify support])
+PHP_ARG_WITH(inotify, whether to enable inotify support,
+[  --with-inotify        Enable inotify support])
 
 if test "$PHP_INOTIFY" != "no"; then
+  SEARCH_PATH="/usr /usr/local"
+  SEARCH_FOR="/sys/inotify.h"
 
-  AC_TRY_RUN([
-   #include <sys/inotify.h>
-   void testfunc(int (*passedfunc)()) {
-   }
-   int main() {
-    testfunc(inotify_init);
-    return 0;
-   }
-  ],[],[
-   AC_MSG_ERROR(Your system does not support inotify)
+  if test "$PHP_INOTIFY" = "yes"; then
+    AC_MSG_CHECKING([for libinotify headers in default path])
+    for i in $SEARCH_PATH ; do
+      if test -r $i/include/$SEARCH_FOR; then
+        LIBINOTIFY_DIR=$i
+        AC_MSG_RESULT(found in $i)
+      fi
+    done
+  else
+    AC_MSG_CHECKING([for libinotify headers in $PHP_INOTIFY])
+    if test -r $PHP_INOTIFY/$SEARCH_FOR; then
+      LIBINOTIFY_DIR=$PHP_INOTIFY
+      AC_MSG_RESULT([found])
+    fi
+  fi
+
+  if test -z "$LIBINOTIFY_DIR"; then
+    AC_MSG_RESULT([not found])
+    AC_MSG_ERROR([Cannot find libevent headers])
+  fi
+
+  LIBNAME=inotify
+  LIBSYMBOL=inotify_init
+
+  if test "x$PHP_LIBDIR" = "x"; then
+    PHP_LIBDIR=lib
+  fi
+
+  PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
+  [
+    PHP_ADD_INCLUDE($LIBINOTIFY_DIR/include)
+    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $LIBINOTIFY_DIR/$PHP_LIBDIR, INOTIFY_SHARED_LIBADD)
+  ],[
+    AC_MSG_ERROR([Your system does not support inotify])
+  ],[
+    -L$LIBINOTIFY_DIR/$PHP_LIBDIR
   ])
 
+  PHP_SUBST(INOTIFY_SHARED_LIBADD)
   PHP_NEW_EXTENSION(inotify, inotify.c, $ext_shared)
 fi
