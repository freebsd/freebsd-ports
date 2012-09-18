--- ./src/src.pro.orig	2011-12-12 21:27:25.000000000 +0000
+++ ./src/src.pro	2012-09-13 21:26:00.215566381 +0000
@@ -5,7 +5,7 @@
 INCLUDEPATH += ./widgets ../include
 RESOURCES   = debugger.qrc
 DESTDIR     = ../
-target.path = /bin/
+target.path = $$PREFIX/bin/
 INSTALLS    += target 
 QT          += xml
 
