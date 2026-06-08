--- config.m4.orig	2026-06-05 04:27:29 UTC
+++ config.m4
@@ -24,6 +24,9 @@ PHP_ARG_WITH(libbrotli, whether to use system brotli l
 PHP_ARG_WITH(libbrotli, whether to use system brotli library,
 [  --with-libbrotli        Use libbrotli], no, no)
 
+PHP_ARG_ENABLE(apcu, whether to enable APCu support,
+[  --enable-apcu           Enable APCu support], auto, no)
+
 if test "$PHP_BROTLI" != "no"; then
 
   BROTLI_MIN_VERSION=0.6
@@ -132,12 +135,17 @@ if test "$PHP_BROTLI" != "no"; then
     PHP_ADD_BUILD_DIR($ext_builddir/brotli/c/enc)
   fi
 
-  AC_MSG_CHECKING([for APCu includes])
-  if test -f "$phpincludedir/ext/apcu/apc_serializer.h"; then
-    apc_inc_path="$phpincludedir"
-    AC_MSG_RESULT([APCu in $apc_inc_path])
-    AC_DEFINE(HAVE_APCU_SUPPORT, 1, [Whether to enable APCu support])
-  else
-    AC_MSG_RESULT([not found])
+  if test "$PHP_APCU" != "no"; then
+    AC_MSG_CHECKING([for APCu includes])
+    if test -f "$phpincludedir/ext/apcu/apc_serializer.h"; then
+      apc_inc_path="$phpincludedir"
+      AC_MSG_RESULT([APCu in $apc_inc_path])
+      AC_DEFINE(HAVE_APCU_SUPPORT, 1, [Whether to enable APCu support])
+    else
+      if test "$PHP_APCU" != "auto"; then
+        AC_MSG_ERROR([apc_serializer.h header not found])
+      fi
+      AC_MSG_RESULT([not found])
+    fi
   fi
 fi
