--- openscad.pro.orig	2018-04-22 17:21:31.278695000 +0000
+++ openscad.pro	2018-04-22 17:21:39.335408000 +0000
@@ -106,4 +106,8 @@
 QT += widgets concurrent
 
+freebsd* {
+   LIBS += -lcompat
+}
+
 netbsd* {
    QMAKE_LFLAGS += -L/usr/X11R7/lib
