--- src/tl/unit_tests/unit_tests.pro.orig	2022-12-22 22:17:08 UTC
+++ src/tl/unit_tests/unit_tests.pro
@@ -58,5 +58,5 @@ SOURCES = \
 INCLUDEPATH += $$TL_INC
 DEPENDPATH += $$TL_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_tl
+LIBS += $$DESTDIR_UT/libklayout_tl.so
 
