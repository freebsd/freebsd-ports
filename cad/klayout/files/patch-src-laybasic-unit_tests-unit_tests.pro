--- src/laybasic/unit_tests/unit_tests.pro.orig	2021-08-28 16:14:42 UTC
+++ src/laybasic/unit_tests/unit_tests.pro
@@ -21,5 +21,5 @@ SOURCES = \
 INCLUDEPATH += $$TL_INC $$LAYBASIC_INC $$DB_INC $$GSI_INC $$OUT_PWD/../laybasic
 DEPENDPATH += $$TL_INC $$LAYBASIC_INC $$DB_INC $$GSI_INC $$OUT_PWD/../laybasic
 
-LIBS += -L$$DESTDIR_UT -lklayout_laybasic -lklayout_db -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_laybasic.so $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so
 
