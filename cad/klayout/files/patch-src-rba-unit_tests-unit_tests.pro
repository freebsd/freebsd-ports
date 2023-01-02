--- src/rba/unit_tests/unit_tests.pro.orig	2022-12-22 22:17:08 UTC
+++ src/rba/unit_tests/unit_tests.pro
@@ -12,7 +12,7 @@ SOURCES = \
 INCLUDEPATH += $$RBA_INC $$TL_INC $$DB_INC $$GSI_INC
 DEPENDPATH += $$RBA_INC $$TL_INC $$DB_INC $$GSI_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_rba -lklayout_tl -lklayout_db -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_rba.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_gsi.so
 
 !equals(HAVE_QT, "0") || !equals(HAVE_PYTHON, "0") {
   RESOURCES = \
