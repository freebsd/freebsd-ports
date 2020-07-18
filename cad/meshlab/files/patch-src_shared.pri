--- src/shared.pri.orig	2020-05-02 21:26:35 UTC
+++ src/shared.pri
@@ -12,7 +12,7 @@ QT += script
 mac:LIBS += $$MESHLAB_DISTRIB_DIRECTORY/lib/libmeshlab-common.dylib
 win32-msvc:LIBS += $$MESHLAB_DISTRIB_DIRECTORY/lib/meshlab-common.lib -lopengl32 -lGLU32
 win32-g++:LIBS += -lmeshlab-common -lopengl32 -lGLU32
-linux:LIBS += -lmeshlab-common -lGL -lGLU
+LIBS += -L$$MESHLAB_DISTRIB_DIRECTORY/lib -lmeshlab-common -lGL -lGLU
 
 win32-msvc:DEFINES += GLEW_STATIC _USE_MATH_DEFINES
 
