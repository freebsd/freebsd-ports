--- src/gsi/unit_tests/unit_tests.pro.orig	2021-08-28 17:03:32 UTC
+++ src/gsi/unit_tests/unit_tests.pro
@@ -14,5 +14,5 @@ HEADERS += \
 INCLUDEPATH += $$TL_INC $$GSI_INC
 DEPENDPATH += $$TL_INC $$GSI_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so
 
