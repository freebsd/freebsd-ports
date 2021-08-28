--- src/tl/unit_tests/unit_tests.pro.orig	2021-08-28 16:09:42 UTC
+++ src/tl/unit_tests/unit_tests.pro
@@ -54,5 +54,5 @@ SOURCES = \
 INCLUDEPATH += $$TL_INC
 DEPENDPATH += $$TL_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_tl
+LIBS += $$DESTDIR_UT/libklayout_tl.so
 
