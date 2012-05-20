--- AutoQ3D.pro~	2012-05-19 22:52:00.000000000 -0300
+++ AutoQ3D.pro	2012-05-19 22:56:52.000000000 -0300
@@ -8,6 +8,7 @@
 win32:LIBS+= -L$(QTDIR)/plugins/imageformats -lqjpeg4
 
 QT +=	opengl
+LIBS +=	-lGLU
 DEPENDPATH += . \
               src \
               src/cmds \
