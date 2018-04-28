--- openscad.pro.orig	2018-04-19 22:08:08 UTC
+++ openscad.pro
@@ -105,6 +106,10 @@ mingw* {
 CONFIG += qt
 QT += widgets concurrent
 
+freebsd* {
+   LIBS += -lcompat
+}
+
 netbsd* {
    QMAKE_LFLAGS += -L/usr/X11R7/lib
    QMAKE_LFLAGS += -Wl,-R/usr/X11R7/lib
