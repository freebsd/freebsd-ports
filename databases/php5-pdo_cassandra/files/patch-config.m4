--- ./config.m4.orig	2011-12-30 17:41:22.000000000 +0800
+++ ./config.m4	2013-11-14 21:46:12.000000000 +0800
@@ -38,8 +38,18 @@
     PHP_THRIFT_VERSION=`${PKG_CONFIG} thrift --modversion`
 
     AC_MSG_RESULT([found version ${PHP_THRIFT_VERSION}])
+    ac_IFS=$IFS
+    IFS="."
+    set $PHP_THRIFT_VERSION
+    IFS=$ac_IFS
+    dnl workaround for changes of THRIFT-1968
+    THRIFT_VERSION=`expr [$]1 \* 10000 + [$]2 \* 100 + [$]3`
+    if test "$THRIFT_VERSION" -ge "901"; then
+      PHP_THRIFT_INCS="-I`${PKG_CONFIG} thrift --variable=includedir`/thrift"
+    else
+      PHP_THRIFT_INCS=`${PKG_CONFIG} thrift --cflags`
+    fi
     PHP_THRIFT_LIBS=`${PKG_CONFIG} thrift --libs`
-    PHP_THRIFT_INCS=`${PKG_CONFIG} thrift --cflags`
 
     PHP_EVAL_LIBLINE(${PHP_THRIFT_LIBS}, PDO_CASSANDRA_SHARED_LIBADD)
     PHP_EVAL_INCLINE(${PHP_THRIFT_INCS})
