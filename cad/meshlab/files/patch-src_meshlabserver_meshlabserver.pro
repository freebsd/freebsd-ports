--- src/meshlabserver/meshlabserver.pro.orig	2020-05-02 21:24:46 UTC
+++ src/meshlabserver/meshlabserver.pro
@@ -29,7 +29,9 @@ macx:LIBS += $$MESHLAB_DISTRIB_DIRECTORY/meshlab.app/C
 
 win32-msvc:LIBS += -lopengl32 -lGLU32 -L$$MESHLAB_DISTRIB_DIRECTORY/lib -lmeshlab-common
 win32-g++:LIBS += -lmeshlab-common
-linux:LIBS += -lmeshlab-common
+LIBS += -L$$MESHLAB_DISTRIB_DIRECTORY/lib -lmeshlab-common
+
+
 
 win32-msvc:DEFINES += GLEW_STATIC
 
