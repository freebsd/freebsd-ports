--- ./src/src.pro.orig	2011-12-12 22:27:25.000000000 +0100
+++ ./src/src.pro	2013-11-20 18:01:37.379434373 +0100
@@ -5,7 +5,7 @@
 INCLUDEPATH += ./widgets ../include
 RESOURCES   = debugger.qrc
 DESTDIR     = ../
-target.path = /bin/
+target.path = $$PREFIX/bin/
 INSTALLS    += target 
 QT          += xml
 
@@ -241,7 +241,7 @@
 
 	linux-g++*:		QMAKE_LFLAGS += -rdynamic
 	openbsd-g++*:	QMAKE_LFLAGS += -lkvm -Wl,--export-dynamic
-	freebsd-g++*:	QMAKE_LFLAGS += -lkvm -Wl,--export-dynamic
+	freebsd-*:	QMAKE_LFLAGS += -lkvm -Wl,--export-dynamic
 	macx-g++*:		QMAKE_LFLAGS += -rdynamic
 
 
