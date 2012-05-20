--- meshlab/meshlab.pro~	2012-05-20 01:14:08.000000000 -0300
+++ meshlab/meshlab.pro	2012-05-20 01:14:53.000000000 -0300
@@ -1,3 +1,6 @@
+# Qt 4.8 does not add -lGLU automatically with QT=opengl anymore
+LIBS += -lGLU
+
 VCGDIR = ../../../vcglib
 GLEWDIR = ../external/glew-1.5.1
 #CONFIG += debug_and_release
