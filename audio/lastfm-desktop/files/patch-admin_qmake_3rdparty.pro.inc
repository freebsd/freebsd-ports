--- admin/qmake/3rdparty.pro.inc.orig	2013-02-04 11:07:09.028832360 +0400
+++ admin/qmake/3rdparty.pro.inc	2013-02-04 11:07:35.513973069 +0400
@@ -19,7 +19,7 @@
         LIBS += /usr/local/lib/libswresample.dylib
     } else {
         CONFIG += link_pkgconfig
-        PKGCONFIG += libavformat libavcodec libavutil
+        PKGCONFIG += libavformat1 libavcodec1 libavutil1
         packagesExist(libswresample) {
             PKGCONFIG += libswresample
             DEFINES += HAVE_SWRESAMPLE
