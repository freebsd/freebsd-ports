--- src/drc/drc/drc.pro.orig	2021-08-28 17:01:48 UTC
+++ src/drc/drc/drc.pro
@@ -18,5 +18,5 @@ RESOURCES = \
 
 INCLUDEPATH += $$TL_INC $$DB_INC $$GSI_INC $$LYM_INC $$RDB_INC
 DEPENDPATH += $$TL_INC $$DB_INC $$GSI_INC $$LYM_INC $$RDB_INC
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_db -lklayout_gsi -lklayout_lym -lklayout_rdb
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_db.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_lym.so $$DESTDIR/libklayout_rdb.so
 
