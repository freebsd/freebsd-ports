--- src/laybasic/laybasic/laybasic.pro.orig	2022-04-24 08:12:38 UTC
+++ src/laybasic/laybasic/laybasic.pro
@@ -305,15 +305,15 @@ HEADERS = \
 
 INCLUDEPATH += $$TL_INC $$GSI_INC $$DB_INC $$RDB_INC $$LYM_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$DB_INC $$RDB_INC $$LYM_INC
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_db -lklayout_rdb -lklayout_lym
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_db.so $$DESTDIR/libklayout_rdb.so $$DESTDIR/libklayout_lym.so
 
 INCLUDEPATH += $$QTBASIC_INC
 DEPENDPATH += $$QTBASIC_INC
 
 equals(HAVE_QTBINDINGS, "1") {
-  LIBS += -lklayout_qtbasic -lklayout_QtGui -lklayout_QtCore
+  LIBS += $$DESTDIR/libklayout_qtbasic.so $$DESTDIR/libklayout_QtGui.so $$DESTDIR/libklayout_QtCore.so
   greaterThan(QT_MAJOR_VERSION, 4) {
-    LIBS += -lklayout_QtWidgets
+    LIBS += $$DESTDIR/libklayout_QtWidgets.so
   }
 }
 
