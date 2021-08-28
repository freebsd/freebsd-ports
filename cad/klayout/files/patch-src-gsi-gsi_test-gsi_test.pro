--- src/gsi/gsi_test/gsi_test.pro.orig	2021-08-28 17:03:04 UTC
+++ src/gsi/gsi_test/gsi_test.pro
@@ -18,4 +18,4 @@ HEADERS = \
 
 INCLUDEPATH += $$TL_INC $$GSI_INC
 DEPENDPATH += $$TL_INC $$GSI_INC
-LIBS += -L$$DESTDIR -lklayout_tl -lklayout_gsi
+LIBS += $$DESTDIR/libklayout_tl.so $$DESTDIR/libklayout_gsi.so
