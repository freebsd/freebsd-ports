--- src/lay/lay/lay.pro.orig	2022-12-22 22:17:08 UTC
+++ src/lay/lay/lay.pro
@@ -182,18 +182,18 @@ RESOURCES = layBuildInMacros.qrc \
 
 INCLUDEPATH += $$TL_INC $$GSI_INC $$DB_INC $$RDB_INC $$LAYBASIC_INC $$LAYUI_INC $$LAYVIEW_INC $$ANT_INC $$IMG_INC $$EDT_INC $$LYM_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$DB_INC $$RDB_INC $$LAYBASIC_INC $$LAYUI_INC $$LAYVIEW_INC $$ANT_INC $$IMG_INC $$EDT_INC $$LYM_INC
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_db -lklayout_rdb -lklayout_lym -lklayout_laybasic -lklayout_layview -lklayout_layui -lklayout_ant -lklayout_img -lklayout_edt
-
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_db.so $$DESTDIR/libklayout_rdb.so $$DESTDIR/libklayout_lym.so $$DESTDIR/libklayout_laybasic.so $$DESTDIR/libklayout_layview.so $$DESTDIR/libklayout_layui.so $$DESTDIR/libklayout_ant.so $$DESTDIR/libklayout_img.so $$DESTDIR/libklayout_edt.so
+ 
 INCLUDEPATH += $$QTBASIC_INC
 DEPENDPATH += $$QTBASIC_INC
 
 equals(HAVE_QTBINDINGS, "1") {
-  LIBS += -lklayout_qtbasic -lklayout_QtGui -lklayout_QtCore
+  LIBS += $$DESTDIR/libklayout_qtbasic.so $$DESTDIR/libklayout_QtGui.so $$DESTDIR/libklayout_QtCore.so
   !equals(HAVE_QT_XML, "0") {
-    LIBS += -lklayout_QtXml
+    LIBS += $$DESTDIR/libklayout_QtXml.so
   }
   greaterThan(QT_MAJOR_VERSION, 4) {
-    LIBS += -lklayout_QtWidgets
+    LIBS += $$DESTDIR/libklayout_QtWidgets.so
   }
 }
 
@@ -201,16 +201,16 @@ INCLUDEPATH += $$RBA_INC
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
