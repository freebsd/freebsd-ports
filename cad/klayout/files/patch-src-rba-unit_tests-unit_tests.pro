--- src/rba/unit_tests/unit_tests.pro.orig	2021-07-23 08:00:26 UTC
+++ src/rba/unit_tests/unit_tests.pro
@@ -12,6 +12,6 @@ SOURCES = \
 INCLUDEPATH += $$RBA_INC $$TL_INC $$DB_INC $$GSI_INC
 DEPENDPATH += $$RBA_INC $$TL_INC $$DB_INC $$GSI_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_rba -lklayout_tl -lklayout_db -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_rba.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_gsi.so
 
-RESOURCES = unit_tests.qrc \
+RESOURCES = unit_tests.qrc
