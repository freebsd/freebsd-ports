--- ./tools/qvfb/qvfb.pro.orig	2012-01-08 16:32:17.921428981 +0100
+++ ./tools/qvfb/qvfb.pro	2012-01-08 16:33:01.611355995 +0100
@@ -38,8 +38,6 @@
 
 !embedded {
     DEFINES         += QT_NO_QWS_SIGNALHANDLER
-    HEADERS         += ../../src/gui/embedded/qlock_p.h
-    SOURCES         += ../../src/gui/embedded/qlock.cpp
 }
 
 include(../shared/deviceskin/deviceskin.pri)
