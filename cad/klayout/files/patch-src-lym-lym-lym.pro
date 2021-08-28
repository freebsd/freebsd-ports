--- src/lym/lym/lym.pro.orig	2021-08-28 16:46:14 UTC
+++ src/lym/lym/lym.pro
@@ -20,22 +20,22 @@ HEADERS = \
 INCLUDEPATH += $$TL_INC $$GSI_INC
 DEPENDPATH += $$TL_INC $$GSI_INC
 
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so
 
 INCLUDEPATH += $$RBA_INC
 DEPENDPATH += $$RBA_INC
 
 equals(HAVE_RUBY, "1") {
-  LIBS += -lklayout_rba
+  LIBS += $$DESTDIR/libklayout_rba.so
 } else {
-  LIBS += -lklayout_rbastub
+  LIBS += $$DESTDIR/libklayout_rbastub.so
 }
 
 INCLUDEPATH += $$PYA_INC
 DEPENDPATH += $$PYA_INC
 
 equals(HAVE_PYTHON, "1") {
-  LIBS += -lklayout_pya
+  LIBS += $$DESTDIR/libklayout_pya.so
 } else {
-  LIBS += -lklayout_pyastub
+  LIBS += $$DESTDIR/libklayout_pyastub.so
 }
