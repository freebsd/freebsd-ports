--- ./infomanager.cpp.orig	2010-01-13 16:32:23.000000000 -0500
+++ ./infomanager.cpp	2010-02-05 01:27:39.000000000 -0500
@@ -22,6 +22,7 @@
 #include <QtGui/QGraphicsWidget>
 
 #include <KDebug>
+#include <KStandardDirs>
 
 #include "playercontroller.h"
 
@@ -105,9 +106,11 @@
     if (metadata.value("arturl").toString() != QString()) {
         emit updateCover(metadata.value("arturl").toString());
     } else if (mode == QString("lastfm")) {
-        emit updateCover("file:///usr/share/apps/amarok/images/lastfm-default-cover.png");
+        QString lastfmcover = KGlobal::dirs()->findResource("data", QString("amarok/images/lastfm-default-cover.png"));
+        emit updateCover(lastfmcover);
     } else {
-        emit updateCover("file:///usr/share/apps/amarok/images/nocover.png");
+        QString nocover = KGlobal::dirs()->findResource("data", QString("amarok/images/nocover.png"));
+        emit updateCover(nocover);
     }
 
     emit updateInfos(metadata.value("artist").toString(),
