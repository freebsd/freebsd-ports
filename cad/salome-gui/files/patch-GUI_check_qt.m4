--- adm_local/unix/config_files/check_qt.m4.orig	2009-12-01 20:59:03.000000000 +0600
+++ adm_local/unix/config_files/check_qt.m4	2010-01-13 16:57:12.000000000 +0600
@@ -153,11 +153,11 @@
 #
 if  test "x$qt_ok" = "xyes"
 then
-  if test -f ${QTDIR}/bin/moc
+  if test -f ${QTDIR}/bin/moc-qt4
   then
-    MOC=${QTDIR}/bin/moc
+    MOC=${QTDIR}/bin/moc-qt4
   else
-    AC_PATH_PROG(MOC, moc)
+    AC_PATH_PROG(MOC, moc-qt4)
   fi
   if test "x$MOC" = "x"
   then
@@ -189,9 +189,9 @@
 #
 if  test "x$qt_ok" = "xyes"
 then
-  if test -f ${QTDIR}/bin/uic
+  if test -f ${QTDIR}/bin/uic-qt4
   then
-    UIC=${QTDIR}/bin/uic
+    UIC=${QTDIR}/bin/uic-qt4
   else
     AC_PATH_PROG(UIC, uic)
   fi
@@ -246,11 +246,11 @@
 #
 if  test "x$qt_ok" = "xyes"
 then
-  if test -f ${QTDIR}/bin/lrelease
+  if test -f ${QTDIR}/bin/lrelease-qt4
   then
-    LRELEASE=${QTDIR}/bin/lrelease
+    LRELEASE=${QTDIR}/bin/lrelease-qt4
   else
-    AC_PATH_PROG(LRELEASE, lrelease)
+    AC_PATH_PROG(LRELEASE, lrelease-qt4)
   fi
   if test "x$LRELEASE" = "x"
   then
