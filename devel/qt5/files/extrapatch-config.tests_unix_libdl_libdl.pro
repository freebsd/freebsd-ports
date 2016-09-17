FreeBSD does not have -ldl.
This has been fixed differently upstream in https://codereview.qt-project.org/#/c/159318/
--- config.tests/unix/libdl/libdl.pro.orig	2016-04-23 14:20:03.489678000 +0200
+++ config.tests/unix/libdl/libdl.pro	2016-04-23 14:20:14.836383000 +0200
@@ -1,3 +1,3 @@
 SOURCES = libdl.cpp
 CONFIG -= qt dylib
-!qnx: LIBS += -ldl
+!qnx:!freebsd: LIBS += -ldl
