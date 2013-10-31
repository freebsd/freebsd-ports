--- meshlab/meshlab.pro.orig	2012-05-30 16:32:44.000000000 +0200
+++ meshlab/meshlab.pro	2013-05-08 10:34:55.000000000 +0200
@@ -136,6 +136,9 @@
 linux-g++-64:LIBS += -L../external/lib/linux-g++-64 -L../distrib -lcommon -lGLU
 linux-g++-64:QMAKE_RPATHDIR += ../distrib
 
+LIBS += -L../external/jhead-2.95 ../common/libcommon.a -lGLU -ljhead
+QMAKE_RPATHDIR += ../distrib
+
 # uncomment in your local copy only in emergency cases.
 # We should never be too permissive
 # win32-g++:QMAKE_CXXFLAGS += -fpermissive
