--- dependencies/ogrenew/RenderSystems/GL/src/GLX/OgreGLXGLSupport.cpp.orig	2009-02-09 02:40:24.000000000 +0300
+++ dependencies/ogrenew/RenderSystems/GL/src/GLX/OgreGLXGLSupport.cpp	2009-08-13 06:36:28.000000000 +0400
@@ -73,6 +73,7 @@
 	optVideoMode.possibleValues.push_back("1280 x 960");
 	optVideoMode.possibleValues.push_back("1280 x 1024");
 	optVideoMode.possibleValues.push_back("1600 x 1200");
+	optVideoMode.possibleValues.push_back("1920 x 1080");
 
 	optVideoMode.currentValue = "800 x 600";
 
