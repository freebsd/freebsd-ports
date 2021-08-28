--- src/lay/unit_tests/unit_tests.pro.orig	2021-08-28 17:29:41 UTC
+++ src/lay/unit_tests/unit_tests.pro
@@ -13,5 +13,5 @@ SOURCES = \
 INCLUDEPATH += $$LAY_INC $$TL_INC $$LAYBASIC_INC $$DB_INC $$GSI_INC $$ANT_INC $$IMG_INC $$RDB_INC
 DEPENDPATH += $$LAY_INC $$TL_INC $$LAYBASIC_INC $$DB_INC $$GSI_INC $$ANT_INC $$IMG_INC $$RDB_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_lay -lklayout_laybasic -lklayout_db -lklayout_tl -lklayout_gsi -lklayout_ant -lklayout_img -lklayout_rdb
+LIBS += $$DESTDIR_UT/libklayout_lay.so $$DESTDIR_UT/libklayout_laybasic.so $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so $$DESTDIR_UT/libklayout_ant.so $$DESTDIR_UT/libklayout_img.so $$DESTDIR_UT/libklayout_rdb.so
 
