--- m4/geda-guile.m4.orig	2018-12-11 19:24:41 UTC
+++ m4/geda-guile.m4
@@ -34,9 +34,20 @@ AC_DEFUN([AX_CHECK_GUILE],
   GUILE_MIN_MINOR=`echo ${GUILE_MIN_VER} | sed -e 's;[[^\.]]*\.;;' -e 's;\..*;;g'`
   GUILE_MIN_TEENY=`echo ${GUILE_MIN_VER} | sed -e 's;.*\.;;'`
 
-  PKG_CHECK_MODULES(GUILE, [guile-2.0 >= $GUILE_MIN_VER],
-                           [GUILE_PKG_NAME=guile-2.0],
-                           [AC_MSG_ERROR([you need at least version ${GUILE_MIN_VER} of guile])])
+  _found_pkg_config_guile=yes
+  PKG_CHECK_MODULES(GUILE, [guile-2.2 >= $GUILE_MIN_VER],
+                           [GUILE_PKG_NAME=guile-2.2], [_found_pkg_config_guile=no])
+
+  if test "${_found_pkg_config_guile}" = "no" ; then
+   PKG_CHECK_MODULES(GUILE, [guile-2.0 >= $GUILE_MIN_VER],
+                            [_found_pkg_config_guile=yes
+                             GUILE_PKG_NAME=guile-2.0],
+                            [_found_pkg_config_guile=no])
+  fi
+
+  if test "${_found_pkg_config_guile}" = "no" ; then
+    AC_MSG_ERROR([you need at least version ${GUILE_MIN_VER} of guile])
+  fi
 
   AC_SUBST([GUILE_PKG_NAME])
 
