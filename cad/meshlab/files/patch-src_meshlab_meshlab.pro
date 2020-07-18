--- src/meshlab/meshlab.pro.orig	2020-05-03 08:34:34 UTC
+++ src/meshlab/meshlab.pro
@@ -143,9 +143,9 @@ macx:QMAKE_POST_LINK += "\
 #	win32-g++:release:LIBS 		+= -L../common/release -lcommon
 #}
 
-linux:LIBS += \
+LIBS += \
     -lmeshlab-common -lGLU \
-    -L$$MESHLAB_DISTRIB_DIRECTORY/lib/linux -ljhead
+    -L$$MESHLAB_DISTRIB_DIRECTORY/lib -L$$EXIF_DIR -ljhead
 
 !CONFIG(system_glew) {
 	INCLUDEPATH *= $$GLEWDIR/include
