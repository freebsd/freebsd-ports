--- src/klayout_main/klayout_main/klayout_main.pro.orig	2022-12-22 22:17:08 UTC
+++ src/klayout_main/klayout_main/klayout_main.pro
@@ -24,52 +24,52 @@ win32 {
 INCLUDEPATH += $$DOC_INC $$ICONS_INC $$QTBASIC_INC
 DEPENDPATH += $$DOC_INC $$ICONS_INC $$QTBASIC_INC
 
-LIBS += -lklayout_doc -lklayout_icons
+LIBS += $$DESTDIR/libklayout_doc.so $$DESTDIR/libklayout_icons.so
 
 equals(HAVE_QTBINDINGS, "1") {
 
-  LIBS += -lklayout_qtbasic -lklayout_QtGui
+  LIBS += $$DESTDIR/libklayout_qtbasic.so $$DESTDIR/libklayout_QtGui.so
 
   !equals(HAVE_QT_XML, "0") {
-    LIBS += -lklayout_QtXml
+    LIBS += $$DESTDIR/libklayout_QtXml.so
   }
   !equals(HAVE_QT_NETWORK, "0") {
-    LIBS += -lklayout_QtNetwork
+    LIBS += $$DESTDIR/libklayout_QtNetwork.so
   }
   !equals(HAVE_QT_SQL, "0") {
-    LIBS += -lklayout_QtSql
+    LIBS += $$DESTDIR/libklayout_QtSql.so
   }
   !equals(HAVE_QT_DESIGNER, "0") {
-    LIBS += -lklayout_QtDesigner
+    LIBS += $$DESTDIR/libklayout_QtDesigner.so
   }
   !equals(HAVE_QT_UITOOLS, "0") {
-    LIBS += -lklayout_QtUiTools
+    LIBS += $$DESTDIR/libklayout_QtUiTools.so
   }
 
   greaterThan(QT_MAJOR_VERSION, 4) {
 
-    LIBS += -lklayout_QtWidgets
+    LIBS += $$DESTDIR/libklayout_QtWidgets.so
 
     !equals(HAVE_QT_MULTIMEDIA, "0") {
-      LIBS += -lklayout_QtMultimedia
+      LIBS += $$DESTDIR/libklayout_QtMultimedia.so
     }
     !equals(HAVE_QT_PRINTSUPPORT, "0") {
-      LIBS += -lklayout_QtPrintSupport
+      LIBS += $$DESTDIR/libklayout_QtPrintSupport.so
     }
     !equals(HAVE_QT_SVG, "0") {
-      LIBS += -lklayout_QtSvg
+      LIBS += $$DESTDIR/libklayout_QtSvg.so
     }
     !equals(HAVE_QT_XML, "0") {
-      LIBS += -lklayout_QtXmlPatterns
+      LIBS += $$DESTDIR/libklayout_QtXmlPatterns.so
     }
 
   }
 
   greaterThan(QT_MAJOR_VERSION, 5) {
 
-    LIBS += -lklayout_QtCore5Compat
-    LIBS -= -lklayout_QtXmlPatterns
-    LIBS -= -lklayout_QtDesigner
+    LIBS += $$DESTDIR/libklayout_QtCore5Compat.so
+    LIBS -= $$DESTDIR/libklayout_QtXmlPatterns.so
+    LIBS -= $$DESTDIR/libklayout_QtDesigner.so
 
   }
 
