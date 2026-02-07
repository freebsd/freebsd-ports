--- src/klayout_main/tests/tests.pro.orig	2021-08-28 16:12:22 UTC
+++ src/klayout_main/tests/tests.pro
@@ -12,5 +12,5 @@ SOURCES = \
 INCLUDEPATH += $$RBA_INC $$TL_INC $$DB_INC $$GSI_INC
 DEPENDPATH += $$RBA_INC $$TL_INC $$DB_INC $$GSI_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_rba -lklayout_tl -lklayout_db -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_rba.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_gsi.so
 
