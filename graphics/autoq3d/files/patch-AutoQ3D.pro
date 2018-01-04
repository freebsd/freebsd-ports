--- AutoQ3D.pro.orig	2016-03-24 23:43:09 UTC
+++ AutoQ3D.pro
@@ -8,6 +8,7 @@ RC_FILE=AutoQ3D.rc
 win32:LIBS+= -L$(QTDIR)/plugins/imageformats -lqjpeg4
 
 QT +=	opengl
+LIBS +=	-lGLU
 DEPENDPATH += . \
               src \
               src/cmds \
