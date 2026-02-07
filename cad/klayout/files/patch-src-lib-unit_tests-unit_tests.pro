--- src/lib/unit_tests/unit_tests.pro.orig	2021-08-28 17:04:53 UTC
+++ src/lib/unit_tests/unit_tests.pro
@@ -12,5 +12,5 @@ SOURCES = \
 INCLUDEPATH += $$LIB_INC $$TL_INC $$DB_INC $$GSI_INC
 DEPENDPATH += $$LIB_INC $$TL_INC $$DB_INC $$GSI_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_lib -lklayout_db -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_lib.so $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so
 
