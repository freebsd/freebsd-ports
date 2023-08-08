--- src/plugins/tools/view_25d/lay_plugin/lay_plugin.pro.orig	2022-12-22 22:17:08 UTC
+++ src/plugins/tools/view_25d/lay_plugin/lay_plugin.pro
@@ -7,11 +7,12 @@ include($$PWD/../../../lay_plugin.pri)
 INCLUDEPATH += $$RDB_INC $$ANT_INC $$QTBASIC_INC
 DEPENDPATH += $$RDB_INC $$ANT_INC $$QTBASIC_INC
 
-LIBS += -L$$DESTDIR/.. -lklayout_rdb -lklayout_ant
+LIBS += $$DESTDIR/../libklayout_rdb.so $$DESTDIR/../libklayout_ant.so
+
 equals(HAVE_QTBINDINGS, "1") {
-  LIBS += -lklayout_qtbasic -lklayout_QtGui -lklayout_QtCore
+  LIBS += $$DESTDIR/../libklayout_qtbasic.so $$DESTDIR/../libklayout_QtGui.so $$DESTDIR/../libklayout_QtCore.so
   greaterThan(QT_MAJOR_VERSION, 4) {
-    LIBS += -lklayout_QtWidgets
+    LIBS += $$DESTDIR/../libklayout_QtWidgets.so
   }
 }
 
