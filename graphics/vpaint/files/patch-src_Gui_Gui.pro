--- src/Gui/Gui.pro.orig	2020-01-07 15:06:58 UTC
+++ src/Gui/Gui.pro
@@ -65,7 +65,7 @@ win32 {
 }
 
 # GLU
-unix:!macx: LIBS += -lGLU
+unix:!macx: LIBS += -lGLU -lGLEW
 win32 {
     LIBS += glu32.lib
 }
@@ -73,25 +73,6 @@ win32 {
 ###############################################################################
 #                      SHIPPED EXTERNAL LIBRARIES
 
-# Add shipped external libraries to includepath and dependpath
-INCLUDEPATH += $$PWD/../Third/
-DEPENDPATH += $$PWD/../Third/
-!win32: QMAKE_CXXFLAGS += $$QMAKE_CFLAGS_ISYSTEM $$PWD/../Third/
-
-# Define RELEASE_OR_DEBUG convenient variable
-CONFIG(release, debug|release): RELEASE_OR_DEBUG = release
-CONFIG(debug,   debug|release): RELEASE_OR_DEBUG = debug
-
-# GLEW
-win32 {
-    LIBS += -L$$OUT_PWD/../Third/GLEW/$$RELEASE_OR_DEBUG/ -lGLEW
-    win32-g++: PRE_TARGETDEPS += $$OUT_PWD/../Third/GLEW/$$RELEASE_OR_DEBUG/libGLEW.a
-    else:      PRE_TARGETDEPS += $$OUT_PWD/../Third/GLEW/$$RELEASE_OR_DEBUG/GLEW.lib
-}
-else:unix {
-    LIBS += -L$$OUT_PWD/../Third/GLEW/ -lGLEW
-    PRE_TARGETDEPS += $$OUT_PWD/../Third/GLEW/libGLEW.a
-}
 
 
 ###############################################################################
