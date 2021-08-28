--- src/lvs/unit_tests/unit_tests.pro.orig	2021-08-28 16:53:25 UTC
+++ src/lvs/unit_tests/unit_tests.pro
@@ -14,4 +14,5 @@ SOURCES = \
 INCLUDEPATH += $$DRC_INC $$TL_INC $$RDB_INC $$DB_INC $$GSI_INC $$LYM_INC
 DEPENDPATH += $$DRC_INC $$TL_INC $$RDB_INC $$DB_INC $$GSI_INC $$LYM_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_lvs -lklayout_drc -lklayout_rdb -lklayout_db -lklayout_tl -lklayout_gsi -lklayout_lym
+LIBS += $$DESTDIR_UT/libklayout_lvs.so $$DESTDIR_UT/libklayout_drc.so $$DESTDIR_UT/libklayout_rdb.so $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so $$DESTDIR_UT/libklayout_lym.so
+
