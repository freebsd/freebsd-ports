--- src/pymod/unit_tests/unit_tests.pro.orig	2021-08-28 20:05:32 UTC
+++ src/pymod/unit_tests/unit_tests.pro
@@ -34,4 +34,4 @@ msvc {
 INCLUDEPATH += $$DB_INC $$TL_INC $$GSI_INC
 DEPENDPATH += $$DB_INC $$TL_INC $$GSI_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_db -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_db.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so
