--- texstudio.pro.orig	2020-11-08 18:12:21 UTC
+++ texstudio.pro
@@ -366,10 +366,8 @@ isEmpty(USE_SYSTEM_QUAZIP) {
     include(src/quazip/quazip/quazip.pri)
 } else {
         message(System quazip5)
-        isEmpty(QUAZIP_LIB): QUAZIP_LIB = -lquazip5
-        isEmpty(QUAZIP_INCLUDE): QUAZIP_INCLUDE = $${PREFIX}/include/quazip5
-        INCLUDEPATH += $${QUAZIP_INCLUDE}
-        LIBS += $${QUAZIP_LIB}
+        CONFIG += link_pkgconfig
+        PKGCONFIG += quazip1-qt5	
 }
 
 include(src/pdfviewer/pdfviewer.pri)
