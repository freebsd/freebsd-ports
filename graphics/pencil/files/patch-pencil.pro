--- pencil.pro.orig	2008-04-16 14:23:57.000000000 +0000
+++ pencil.pro	2008-04-16 14:19:45.000000000 +0000
@@ -86,5 +86,9 @@
 	SOURCES += src/external/linux/linux.cpp
 	LIBS += -Lliblinux -lming -lpng
 }
+freebsd-g++ {
+	SOURCES += src/external/freebsd/freebsd.cpp
+	LIBS += -lming -lpng
+}
 RESOURCES += pencil.qrc
 QT += xml opengl
