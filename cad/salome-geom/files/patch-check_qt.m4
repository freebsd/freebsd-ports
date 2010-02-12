--- adm_local/unix/config_files/check_qt.m4.orig	2009-10-19 12:42:16.000000000 +0700
+++ adm_local/unix/config_files/check_qt.m4	2009-10-19 12:43:05.000000000 +0700
@@ -153,9 +153,9 @@
 #
 if  test "x$qt_ok" = "xyes"
 then
-  if test -f ${QTDIR}/bin/moc
+  if test -f ${QTDIR}/bin/moc-qt4
   then
-    MOC=${QTDIR}/bin/moc
+    MOC=${QTDIR}/bin/moc-qt4
   else
     AC_PATH_PROG(MOC, moc)
   fi
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
@@ -246,9 +246,9 @@
 #
 if  test "x$qt_ok" = "xyes"
 then
-  if test -f ${QTDIR}/bin/lrelease
+  if test -f ${QTDIR}/bin/lrelease-qt4
   then
-    LRELEASE=${QTDIR}/bin/lrelease
+    LRELEASE=${QTDIR}/bin/lrelease-qt4
   else
     AC_PATH_PROG(LRELEASE, lrelease)
   fi
