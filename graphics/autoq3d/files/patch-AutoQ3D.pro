--- ./AutoQ3D.pro.orig	2012-12-02 18:48:47.000000000 -0500
+++ ./AutoQ3D.pro	2012-12-02 18:48:47.000000000 -0500
@@ -8,6 +8,7 @@
 win32:LIBS+= -L$(QTDIR)/plugins/imageformats -lqjpeg4
 
 QT +=	opengl
+LIBS +=	-lGLU
 DEPENDPATH += . \
               src \
               src/cmds \
