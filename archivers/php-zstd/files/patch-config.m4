--- config.m4.orig	2026-06-05 04:23:54 UTC
+++ config.m4
@@ -27,6 +27,9 @@ PHP_ARG_WITH(libzstd, whether to use system zstd libra
 PHP_ARG_WITH(libzstd, whether to use system zstd library,
 [  --with-libzstd           Use system zstd library], no, no)
 
+PHP_ARG_ENABLE(apcu, whether to enable APCu support,
+[  --enable-apcu           Enable APCu support], auto, no)
+
 if test "$PHP_ZSTD" != "no"; then
 
   LIBZSTD_MIN_VERSION=1.4.0
@@ -105,13 +108,18 @@ dnl APCu
 fi
 
 dnl APCu
-AC_MSG_CHECKING([for APCu includes])
-if test -f "$phpincludedir/ext/apcu/apc_serializer.h"; then
-  apc_inc_path="$phpincludedir"
-  AC_MSG_RESULT([APCu in $apc_inc_path])
-  AC_DEFINE(HAVE_APCU_SUPPORT, 1, [Whether to enable APCu support])
-else
-  AC_MSG_RESULT([not found])
+if test "$PHP_APCU" != "no"; then
+  AC_MSG_CHECKING([for APCu includes])
+  if test -f "$phpincludedir/ext/apcu/apc_serializer.h"; then
+    apc_inc_path="$phpincludedir"
+    AC_MSG_RESULT([APCu in $apc_inc_path])
+    AC_DEFINE(HAVE_APCU_SUPPORT, 1, [Whether to enable APCu support])
+  else
+    if test "$PHP_APCU" != "auto"; then
+      AC_MSG_ERROR([apc_serializer.h header not found])
+    fi
+    AC_MSG_RESULT([not found])
+  fi
 fi
 
 dnl coverage
