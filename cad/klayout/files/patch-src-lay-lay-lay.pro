--- src/lay/lay/lay.pro.orig	2021-07-23 08:00:26 UTC
+++ src/lay/lay/lay.pro
@@ -181,13 +181,13 @@ RESOURCES = layBuildInMacros.qrc \
 
 INCLUDEPATH += $$TL_INC $$GSI_INC $$DB_INC $$RDB_INC $$LAYBASIC_INC $$ANT_INC $$IMG_INC $$EDT_INC $$LYM_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$DB_INC $$RDB_INC $$LAYBASIC_INC $$ANT_INC $$IMG_INC $$EDT_INC $$LYM_INC
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_db -lklayout_rdb -lklayout_lym -lklayout_laybasic -lklayout_ant -lklayout_img -lklayout_edt
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_db.so $$DESTDIR/libklayout_rdb.so $$DESTDIR/libklayout_lym.so $$DESTDIR/libklayout_laybasic.so $$DESTDIR/libklayout_ant.so $$DESTDIR/libklayout_img.so $$DESTDIR/libklayout_edt.so
 
 win32 {
   # for stack trace support:
   # lpsapi for GetModuleFileName and others
   # dbghelp for SymFromAddr and other
-  LIBS += -lpsapi -ldbghelp
+  LIBS += $$DESTDIR/libpsapi.so $$DESTDIR/libdbghelp.so
 }
 
 *bsd* {
@@ -203,12 +203,12 @@ INCLUDEPATH += $$QTBASIC_INC
 DEPENDPATH += $$QTBASIC_INC
 
 equals(HAVE_QTBINDINGS, "1") {
-  LIBS += -lklayout_qtbasic -lklayout_QtGui -lklayout_QtCore
+  LIBS += $$DESTDIR/libklayout_qtbasic.so $$DESTDIR/libklayout_QtGui.so $$DESTDIR/libklayout_QtCore.so
   !equals(HAVE_QT_XML, "0") {
-    LIBS += -lklayout_QtXml
+    LIBS += $$DESTDIR/libklayout_QtXml.so
   }
   equals(HAVE_QT5, "1") {
-    LIBS += -lklayout_QtWidgets
+    LIBS += $$DESTDIR/libklayout_QtWidgets.so
   }
 }
 
@@ -216,16 +216,16 @@ INCLUDEPATH += $$RBA_INC
 DEPENDPATH += $$RBA_INC
 
 equals(HAVE_RUBY, "1") {
-  LIBS += -lklayout_rba
+  LIBS += $$DESTDIR/libklayout_rba.so
 } else {
-  LIBS += -lklayout_rbastub
+  LIBS += $$DESTDIR/libklayout_rbastub.so
 }
 
 INCLUDEPATH += $$PYA_INC
 DEPENDPATH += $$PYA_INC
 
 equals(HAVE_PYTHON, "1") {
-  LIBS += -lklayout_pya
+  LIBS += $$DESTDIR/libklayout_pya.so
 } else {
-  LIBS += -lklayout_pyastub
+  LIBS += $$DESTDIR/libklayout_pyastub.so
 }
