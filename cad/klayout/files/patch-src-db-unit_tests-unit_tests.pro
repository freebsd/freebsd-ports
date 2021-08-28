--- src/db/unit_tests/unit_tests.pro.orig	2021-08-28 17:26:04 UTC
+++ src/db/unit_tests/unit_tests.pro
@@ -87,5 +87,5 @@ SOURCES = \
 INCLUDEPATH += $$TL_INC $$DB_INC $$GSI_INC
 DEPENDPATH += $$TL_INC $$DB_INC $$GSI_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_db -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so
 
