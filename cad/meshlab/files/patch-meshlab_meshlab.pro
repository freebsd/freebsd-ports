--- meshlab/meshlab.pro.orig	2011-02-15 10:39:47.000000000 +0100
+++ meshlab/meshlab.pro	2012-06-21 09:13:21.000000000 +0200
@@ -1,3 +1,6 @@
+# Qt 4.8 does not add -lGLU automatically with QT=opengl anymore
+LIBS += -lGLU
+
 VCGDIR = ../../../vcglib
 GLEWDIR = ../external/glew-1.5.1
 #CONFIG += debug_and_release
@@ -128,12 +131,12 @@
 #	win32-g++:release:LIBS 			+= -L../common/release -lcommon
 #}
 
-linux-g++:LIBS += -L../distrib -lcommon
-linux-g++:QMAKE_RPATHDIR += ../distrib
-linux-g++-32:LIBS += -L../distrib -lcommon
-linux-g++-32:QMAKE_RPATHDIR += ../distrib
-linux-g++-64:LIBS += -L../distrib -lcommon
-linux-g++-64:QMAKE_RPATHDIR += ../distrib
+freebsd-g++:LIBS += $$PWD/../distrib/libcommon.so
+freebsd-g++:QMAKE_RPATHDIR += ../distrib
+freebsd-g++-32:LIBS += $PWD/../distrib/libcommon.so
+freebsd-g++-32:QMAKE_RPATHDIR += ../distrib
+freebsd-g++-64:LIBS += $PWD/../distrib/libcommon.so
+freebsd-g++-64:QMAKE_RPATHDIR += ../distrib
 
 
 # uncomment in your local copy only in emergency cases.
