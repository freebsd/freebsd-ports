--- src/lym/unit_tests/unit_tests.pro.orig	2021-08-28 16:47:48 UTC
+++ src/lym/unit_tests/unit_tests.pro
@@ -12,17 +12,17 @@ SOURCES = \
 INCLUDEPATH += $$RBA_INC $$PYA_INC $$LYM_INC $$TL_INC $$GSI_INC
 DEPENDPATH += $$RBA_INC $$PYA_INC $$LYM_INC $$TL_INC $$GSI_INC
 
-LIBS += -L$$DESTDIR_UT -lklayout_lym -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR_UT/libklayout_lym.so $$DESTDIR_UT/libklayout_tl.so $$DESTDIR_UT/libklayout_gsi.so
 
 equals(HAVE_RUBY, "1") {
-  LIBS += -lklayout_rba
+  LIBS += $$DESTDIR_UT/libklayout_rba.so
 } else {
-  LIBS += -lklayout_rbastub
+  LIBS += $$DESTDIR_UT/libklayout_rbastub.so
 }
 
 equals(HAVE_PYTHON, "1") {
-  LIBS += -lklayout_pya
+  LIBS += $$DESTDIR_UT/libklayout_pya.so
 } else {
-  LIBS += -lklayout_pyastub
+  LIBS += $$DESTDIR_UT/libklayout_pyastub.so
 }
 
