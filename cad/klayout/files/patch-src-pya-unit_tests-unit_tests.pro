--- src/pya/unit_tests/unit_tests.pro.orig	2021-08-28 17:00:21 UTC
+++ src/pya/unit_tests/unit_tests.pro
@@ -12,5 +12,5 @@ SOURCES = \
 INCLUDEPATH += $$PYA_INC $$DB_INC $$TL_INC $$GSI_INC
 DEPENDPATH += $$PYA_INC $$DB_INC $$TL_INC $$GSI_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_pya -lklayout_db -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_pya.so $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so
 
