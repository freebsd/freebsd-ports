--- src/rdb/unit_tests/unit_tests.pro.orig	2021-08-28 16:08:37 UTC
+++ src/rdb/unit_tests/unit_tests.pro
@@ -13,5 +13,5 @@ SOURCES = \
 INCLUDEPATH += $$RDB_INC $$TL_INC $$DB_INC $$GSI_INC
 DEPENDPATH += $$RDB_INC $$TL_INC $$DB_INC $$GSI_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_rdb -lklayout_db -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_rdb.so $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so
 
