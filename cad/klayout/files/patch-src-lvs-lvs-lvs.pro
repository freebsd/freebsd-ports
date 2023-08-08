--- src/lvs/lvs/lvs.pro.orig	2022-12-22 22:17:08 UTC
+++ src/lvs/lvs/lvs.pro
@@ -20,5 +20,5 @@ HEADERS = \
 
 INCLUDEPATH += $$TL_INC $$DB_INC $$GSI_INC $$LYM_INC $$RDB_INC
 DEPENDPATH += $$TL_INC $$DB_INC $$GSI_INC $$LYM_INC $$RDB_INC
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_db -lklayout_gsi -lklayout_lym -lklayout_rdb -lklayout_drc
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_db.so $$DESTDIR/libklayout_gsi.so $$DESTDIR/libklayout_lym.so $$DESTDIR/libklayout_rdb.so $$DESTDIR/libklayout_drc.so
 
