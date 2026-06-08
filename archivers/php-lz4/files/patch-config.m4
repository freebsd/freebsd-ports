--- config.m4.orig	2025-11-07 02:17:19 UTC
+++ config.m4
@@ -27,6 +27,9 @@ PHP_ARG_WITH(lz4-includedir, for lz4 header,
 PHP_ARG_WITH(lz4-includedir, for lz4 header,
 [  --with-lz4-includedir=DIR  lz4 header files], no, no)
 
+PHP_ARG_ENABLE(apcu, whether to enable APCu support,
+[  --enable-apcu           Enable APCu support], auto, no)
+
 if test "$PHP_LZ4" != "no"; then
 
   AC_MSG_CHECKING([searching for liblz4])
@@ -65,13 +68,18 @@ if test "$PHP_LZ4" != "no"; then
     PHP_ADD_INCLUDE([$ext_srcdir/lz4/lib])
   fi
 
-  AC_MSG_CHECKING([for APCu includes])
-  if test -f "$phpincludedir/ext/apcu/apc_serializer.h"; then
-    apc_inc_path="$phpincludedir"
-    AC_MSG_RESULT([APCu in $apc_inc_path])
-    AC_DEFINE(HAVE_APCU_SUPPORT,1,[Whether to enable APCu support])
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
 
