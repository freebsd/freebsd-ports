--- src/unit_tests/unit_tests.pro.orig	2021-07-23 08:00:26 UTC
+++ src/unit_tests/unit_tests.pro
@@ -23,10 +23,10 @@ HEADERS += \
 !win32 {
   LIBS += -ldl
 } else {
-  LIBS += -lshell32
+  LIBS += $$DESTDIR/libshell32.so
 }
 
-LIBS += -lklayout_gsi_test
+LIBS += $$DESTDIR/libklayout_gsi_test.so
 
 !equals(HAVE_QT, "0") {
 
@@ -35,10 +35,10 @@ LIBS += -lklayout_gsi_test
 
   equals(HAVE_QTBINDINGS, "1") {
     !equals(HAVE_QT_XML, "0") {
-      LIBS += -lklayout_QtXml
+      LIBS += $$DESTDIR/libklayout_QtXml.so
     }
     equals(HAVE_QT5, "1") {
-      LIBS += -lklayout_QtWidgets
+      LIBS += $$DESTDIR/libklayout_QtWidgets.so
     }
   }
 
