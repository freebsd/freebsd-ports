--- src/lay/unit_tests/unit_tests.pro.orig	2022-12-22 22:17:08 UTC
+++ src/lay/unit_tests/unit_tests.pro
@@ -14,5 +14,5 @@ SOURCES = \
 INCLUDEPATH += $$LAY_INC $$TL_INC $$LAYBASIC_INC $$LAYUI_INC $$LAYVIEW_INC $$DB_INC $$GSI_INC $$ANT_INC $$IMG_INC $$RDB_INC
 DEPENDPATH += $$LAY_INC $$TL_INC $$LAYBASIC_INC $$LAYUI_INC $$LAYVIEW_INC $$DB_INC $$GSI_INC $$ANT_INC $$IMG_INC $$RDB_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_lay -lklayout_laybasic -lklayout_layui -lklayout_layview -lklayout_db -lklayout_tl -lklayout_gsi -lklayout_ant -lklayout_img -lklayout_rdb
+LIBS += $$DESTDIR_UT/libklayout_lay.so $$DESTDIR_UT/libklayout_laybasic.so $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so $$DESTDIR_UT/libklayout_ant.so $$DESTDIR_UT/libklayout_img.so $$DESTDIR_UT/libklayout_rdb.so
 
