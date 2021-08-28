--- src/klayout_main/klayout_main/klayout_main.pro.orig	2021-08-28 16:11:14 UTC
+++ src/klayout_main/klayout_main/klayout_main.pro
@@ -27,39 +27,39 @@ DEPENDPATH += $$QTBASIC_INC
 
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
 
   equals(HAVE_QT5, "1") {
 
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
