--- src/zip/zip.pro.orig	2018-07-01 14:10:25 UTC
+++ src/zip/zip.pro
@@ -1,6 +1,6 @@
 include( ../../shared.pri )
 
-INCLUDEPATH+=../3rdparty/quazip/src
+# INCLUDEPATH+=../3rdparty/quazip/src
 
 greaterThan(QT_MAJOR_VERSION, 4) {
     INCLUDEPATH += $$[QT_INSTALL_HEADERS]/QtZlib
@@ -23,7 +23,7 @@ else {
     CONFIG += plugin
 }
 TARGET = $${RLIBNAME}zip
-LIBS += -l$${RLIBNAME}core -lquazip
+LIBS += -l$${RLIBNAME}core -lquazip5
 OTHER_FILES += zip.dox
 DEFINES += QCADZIP_LIBRARY
 RC_FILE = zip.rc
