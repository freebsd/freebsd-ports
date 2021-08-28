--- src/edt/unit_tests/unit_tests.pro.orig	2021-08-28 16:59:05 UTC
+++ src/edt/unit_tests/unit_tests.pro
@@ -13,5 +13,5 @@ SOURCES = \
 INCLUDEPATH += $$EDT_INC $$TL_INC $$LAYBASIC_INC $$DB_INC $$GSI_INC
 DEPENDPATH += $$EDT_INC $$TL_INC $$LAYBASIC_INC $$DB_INC $$GSI_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_edt -lklayout_laybasic -lklayout_db -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_edt.so $$DESTDIR_UT/libklayout_laybasic.so $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so
 
