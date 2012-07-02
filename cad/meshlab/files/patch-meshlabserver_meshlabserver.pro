--- meshlabserver/meshlabserver.pro.bak	2011-01-25 08:49:46.000000000 +0100
+++ meshlabserver/meshlabserver.pro	2012-06-21 09:29:05.000000000 +0200
@@ -25,12 +25,12 @@
 win32-msvc2008:  LIBS += -L../distrib -lcommon
 win32-msvc2010:  LIBS += -L../distrib -lcommon
 win32-g++:  LIBS += -L../distrib -lcommon
-linux-g++:  LIBS += -L../distrib -lcommon
-linux-g++:QMAKE_RPATHDIR += ../distrib
-linux-g++-32:  LIBS += -L../distrib -lcommon
-linux-g++-32:QMAKE_RPATHDIR += ../distrib
-linux-g++-64:  LIBS += -L../distrib -lcommon
-linux-g++-64:QMAKE_RPATHDIR += ../distrib
+freebsd-g++:  LIBS += $$PWD/../distrib/libcommon.so
+freebsd-g++:QMAKE_RPATHDIR += ../distrib
+freebsd-g++-32:  LIBS += $$PWD/../distrib/libcommon.so
+freebsd-g++-32:QMAKE_RPATHDIR += ../distrib
+freebsd-g++-64:  LIBS += $$PWD/../distrib/libcommon.so
+freebsd-g++-64:QMAKE_RPATHDIR += ../distrib
 #CONFIG (release,debug | release) {
 #	win32-msvc2005:release:  LIBS += -L../common/release -lcommon
 #	win32-msvc2008:release:  LIBS += -L../common/release -lcommon
