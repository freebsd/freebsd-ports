--- src/unit_tests/unit_tests.pro.orig	2022-12-22 22:17:08 UTC
+++ src/unit_tests/unit_tests.pro
@@ -11,7 +11,7 @@ include($$PWD/../with_all_libs.pri)
   INCLUDEPATH += $$DOC_INC $$ICONS_INC
   DEPENDPATH += $$DOC_INC $$ICONS_INC
 
-  LIBS += -lklayout_doc -lklayout_icons
+  LIBS += $$DESTDIR/libklayout_doc.so $$DESTDIR/libklayout_icons.so
 
 }
 
@@ -34,10 +34,10 @@ HEADERS += \
 !win32 {
   LIBS += -ldl
 } else {
-  LIBS += -lshell32
+  LIBS += $$DESTDIR/libshell32.so
 }
 
-LIBS += -lklayout_gsi_test
+LIBS += $$DESTDIR/libklayout_gsi_test.so
 
 !equals(HAVE_QT, "0") {
 
@@ -46,10 +46,10 @@ LIBS += -lklayout_gsi_test
 
   equals(HAVE_QTBINDINGS, "1") {
     !equals(HAVE_QT_XML, "0") {
-      LIBS += -lklayout_QtXml
+      LIBS += $$DESTDIR/libklayout_QtXml.so
     }
     greaterThan(QT_MAJOR_VERSION, 4) {
-      LIBS += -lklayout_QtWidgets
+      LIBS += $$DESTDIR/libklayout_QtWidgets.so
     }
   }
 
