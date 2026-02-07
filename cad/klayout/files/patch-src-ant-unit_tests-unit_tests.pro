--- src/ant/unit_tests/unit_tests.pro.orig	2021-08-28 17:19:11 UTC
+++ src/ant/unit_tests/unit_tests.pro
@@ -12,5 +12,5 @@ SOURCES = \
 INCLUDEPATH += $$ANT_INC $$TL_INC $$LAYBASIC_INC $$DB_INC $$GSI_INC
 DEPENDPATH += $$ANT_INC $$TL_INC $$LAYBASIC_INC $$DB_INC $$GSI_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_ant -lklayout_laybasic -lklayout_db -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_ant.so $$DESTDIR_UT/libklayout_laybasic.so $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so
 
