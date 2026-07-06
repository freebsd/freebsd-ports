--- config.m4.orig	2026-06-09 03:05:00 UTC
+++ config.m4
@@ -4,14 +4,22 @@
 Make sure that the comment is aligned:
 [  --with-msgpack             Include msgpack support])
 
+PHP_ARG_ENABLE(apcu, whether to enable APCu support,
+[  --enable-apcu           Enable APCu support], auto, no)
+
 if test "$PHP_MSGPACK" != "no"; then
-  AC_MSG_CHECKING([for APC/APCU includes])
-  if test -f "$phpincludedir/ext/apcu/apc_serializer.h"; then
-    apc_inc_path="$phpincludedir"
-    AC_MSG_RESULT([APCU in $apc_inc_path])
-    AC_DEFINE(HAVE_APCU_SUPPORT,1,[Whether to enable apcu support])
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
 
   PHP_NEW_EXTENSION(msgpack, msgpack.c msgpack_pack.c msgpack_unpack.c msgpack_class.c msgpack_convert.c, $ext_shared)
