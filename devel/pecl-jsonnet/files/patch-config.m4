--- config.m4.orig	2016-08-07 07:36:22 UTC
+++ config.m4
@@ -53,12 +53,9 @@ AC_DEFUN([AC_JSONNET_EPOLL],
 ])
 
 if test "$PHP_JSONNET" != "no"; then
-  THIS_DIR=`dirname $0`
-  MAKE_LIB_JSONNET=`cd ${THIS_DIR}/libjsonnet && make libjsonnet.so`
-
   # --with-jsonnet -> check with-path
   SEARCH_PATH="/usr/local/lib"
-  SEARCH_FOR="libjsonnet.h"
+  SEARCH_FOR="include/libjsonnet.h"
   if test -r $PHP_JSONNET/$SEARCH_FOR; then # path given as parameter
     JSONNET_DIR=$PHP_JSONNET
   else # search default path list
@@ -77,13 +74,12 @@ if test "$PHP_JSONNET" != "no"; then
   fi
 
   # --with-jsonnet -> add include path
-  PHP_ADD_INCLUDE($JSONNET_DIR)
+  PHP_ADD_INCLUDE($JSONNET_DIR/include)
 
   # --with-jsonnet -> check for lib and symbol presence
 
-    PHP_ADD_INCLUDE($JSONNET_DIR)
-    PHP_EVAL_LIBLINE($JSONNET_DIR, JSONNET_SHARED_LIBADD)
-    PHP_ADD_LIBRARY_WITH_PATH(jsonnet, $JSONNET_DIR, JSONNET_SHARED_LIBADD)
+    PHP_EVAL_LIBLINE($JSONNET_DIR/lib, JSONNET_SHARED_LIBADD)
+    PHP_ADD_LIBRARY_WITH_PATH(jsonnet, $JSONNET_DIR/lib, JSONNET_SHARED_LIBADD)
 
     AC_JSONNET_EPOLL()
 
