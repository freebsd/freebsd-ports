--- src/LastFMHelper/controlinterface.h.orig	2007-09-24 23:41:54.000000000 +0200
+++ src/LastFMHelper/controlinterface.h	2007-09-24 23:42:01.000000000 +0200
@@ -24,6 +24,7 @@
 
 #include <QObject>
 #include <QMutex>
+#include <QCoreApplication>
 
 class ControlInterface : public QObject
 {
