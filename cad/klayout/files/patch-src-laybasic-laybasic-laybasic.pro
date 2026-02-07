--- src/laybasic/laybasic/laybasic.pro.orig	2022-12-22 22:17:08 UTC
+++ src/laybasic/laybasic/laybasic.pro
@@ -139,15 +139,15 @@ HEADERS += \
 
 INCLUDEPATH += $$TL_INC $$GSI_INC $$DB_INC $$RDB_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$DB_INC $$RDB_INC
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi -lklayout_db -lklayout_rdb 
-
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_db.so $$DESTDIR/libklayout_rdb.so
+ 
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
 
