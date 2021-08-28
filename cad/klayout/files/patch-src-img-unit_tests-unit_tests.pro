--- src/img/unit_tests/unit_tests.pro.orig	2021-08-28 16:51:37 UTC
+++ src/img/unit_tests/unit_tests.pro
@@ -13,5 +13,5 @@ SOURCES = \
 INCLUDEPATH += $$IMG_INC $$DB_INC $$TL_INC $$LAYBASIC_INC $$GSI_INC
 DEPENDPATH += $$IMG_INC $$DB_INC $$TL_INC $$LAYBASIC_INC $$GSI_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_img -lklayout_laybasic -lklayout_db -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_img.so $$DESTDIR_UT/libklayout_laybasic.so $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so
 
