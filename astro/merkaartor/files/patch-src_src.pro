Link against the right library name for archivers/quazip-qt5.
--- src/src.pro.orig	2015-07-19 14:50:09 UTC
+++ src/src.pro
@@ -15,7 +15,8 @@ isEmpty(SYSTEM_QUAZIP) {
   DEFINES += QUAZIP_STATIC
   include(../3rdparty/quazip-0.7/quazip.pri)
 } else {
-  LIBS += -lquazip
+  CONFIG += link_pkgconfig
+  PKGCONFIG += quazip1-qt5
 }
 
 #Qt Version
