--- src/with_all_libs.pri.orig	2022-12-22 22:17:08 UTC
+++ src/with_all_libs.pri
@@ -2,38 +2,38 @@
 INCLUDEPATH += $$RBA_INC $$PYA_INC $$TL_INC $$GSI_INC $$DB_INC $$RDB_INC $$LYM_INC $$LAYBASIC_INC $$LAYVIEW_INC $$ANT_INC $$IMG_INC $$EDT_INC $$LIB_INC $$VERSION_INC
 DEPENDPATH += $$RBA_INC $$PYA_INC $$TL_INC $$GSI_INC $$DB_INC $$RDB_INC $$LYM_INC $$LAYBASIC_INC $$LAYVIEW_INC $$ANT_INC $$IMG_INC $$EDT_INC $$LIB_INC $$VERSION_INC
 
-LIBS += "$$PYTHONLIBFILE" "$$RUBYLIBFILE" -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_db -lklayout_rdb -lklayout_lym -lklayout_laybasic -lklayout_layview -lklayout_ant -lklayout_img -lklayout_edt -lklayout_lib
+LIBS += "$$PYTHONLIBFILE" "$$RUBYLIBFILE" $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_db.so $$DESTDIR/libklayout_rdb.so $$DESTDIR/libklayout_lym.so $$DESTDIR/libklayout_laybasic.so $$DESTDIR/libklayout_layview.so $$DESTDIR/libklayout_ant.so $$DESTDIR/libklayout_img.so $$DESTDIR/libklayout_edt.so $$DESTDIR/libklayout_lib.so
 
 !equals(HAVE_QT, "0") {
 
   INCLUDEPATH += $$LAYUI_INC $$LAY_INC
   DEPENDPATH += $$LAYUI_INC $$LAY_INC
 
-  LIBS += -L$$DESTDIR -lklayout_layui -lklayout_lay
+  LIBS += $$DESTDIR/libklayout_layui.so $$DESTDIR/libklayout_lay.so
 
   equals(HAVE_QTBINDINGS, "1") {
-    LIBS += -lklayout_qtbasic -lklayout_QtGui -lklayout_QtCore
+    LIBS += $$DESTDIR/libklayout_qtbasic.so $$DESTDIR/libklayout_QtGui.so $$DESTDIR/libklayout_QtCore.so
   }
 
 }
 
 equals(HAVE_RUBY, "1") {
-  LIBS += -lklayout_rba
+  LIBS += $$DESTDIR/libklayout_rba.so
 } else {
-  LIBS += -lklayout_rbastub
+  LIBS += $$DESTDIR/libklayout_rbastub.so
 }
 
 equals(HAVE_PYTHON, "1") {
-  LIBS += -lklayout_pya
+  LIBS += $$DESTDIR/libklayout_pya.so
 } else {
-  LIBS += -lklayout_pyastub
+  LIBS += $$DESTDIR/libklayout_pyastub.so
 }
 
 equals(HAVE_RUBY, "1") {
   # DRC is only available with Ruby
   INCLUDEPATH += $$DRC_INC $$LVS_INC
   DEPENDPATH += $$DRC_INC $$LVS_INC
-  LIBS += -lklayout_drc -lklayout_lvs
+  LIBS += $$DESTDIR/libklayout_drc.so $$DESTDIR/libklayout_lvs.so
 }
 
 msvc {
