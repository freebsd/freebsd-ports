--- pencil.pro.orig	2008-01-20 10:04:02.000000000 +0100
+++ pencil.pro	2013-06-26 15:47:47.000000000 +0200
@@ -86,5 +86,13 @@
 	SOURCES += src/external/linux/linux.cpp
 	LIBS += -Lliblinux -lming -lpng
 }
+freebsd-g++ {
+	SOURCES += src/external/freebsd/freebsd.cpp
+	LIBS += -lming -lpng
+}
+freebsd-clang {
+	SOURCES += src/external/freebsd/freebsd.cpp
+	LIBS += -lming -lpng
+}
 RESOURCES += pencil.qrc
 QT += xml opengl
