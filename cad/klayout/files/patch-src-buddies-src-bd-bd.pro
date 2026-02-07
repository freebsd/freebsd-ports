--- src/buddies/src/bd/bd.pro.orig	2021-08-28 16:26:18 UTC
+++ src/buddies/src/bd/bd.pro
@@ -34,24 +34,24 @@ RESOURCES = \
 
 INCLUDEPATH += $$TL_INC $$GSI_INC $$VERSION_INC $$DB_INC $$LIB_INC $$RDB_INC $$LYM_INC
 DEPENDPATH += $$TL_INC $$GSI_INC $$VERSION_INC $$DB_INC $$LIB_INC $$RDB_INC $$LYM_INC
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_db -lklayout_gsi -lklayout_lib -lklayout_rdb -lklayout_lym
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_db.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_lib.so $$DESTDIR/libklayout_rdb.so $$DESTDIR/libklayout_lym.so
 
 INCLUDEPATH += $$RBA_INC
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
 
 
