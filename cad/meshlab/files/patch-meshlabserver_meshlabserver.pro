--- meshlabserver/meshlabserver.pro.orig	2011-10-14 18:34:48.000000000 +0200
+++ meshlabserver/meshlabserver.pro	2013-05-08 10:36:08.000000000 +0200
@@ -31,6 +31,8 @@
 linux-g++-32:QMAKE_RPATHDIR += ../distrib
 linux-g++-64:  LIBS += -L../distrib -lcommon
 linux-g++-64:QMAKE_RPATHDIR += ../distrib
+LIBS += ../common/libcommon.a -L../external/jhead-2.95 -ljhead
+QMAKE_RPATHDIR += ../distrib
 #CONFIG (release,debug | release) {
 #	win32-msvc2005:release:  LIBS += -L../common/release -lcommon
 #	win32-msvc2008:release:  LIBS += -L../common/release -lcommon
