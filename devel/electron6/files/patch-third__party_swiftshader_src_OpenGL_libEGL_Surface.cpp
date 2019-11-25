--- third_party/swiftshader/src/OpenGL/libEGL/Surface.cpp.orig	2019-09-10 11:17:34 UTC
+++ third_party/swiftshader/src/OpenGL/libEGL/Surface.cpp
@@ -360,7 +360,7 @@ bool WindowSurface::checkForResize()
 
 		int windowWidth = windowAttributes.width;
 		int windowHeight = windowAttributes.height;
-	#elif defined(__linux__)
+	#elif defined(__linux__) || defined(__FreeBSD__)
 		// Non X11 linux is headless only
 		int windowWidth = 100;
 		int windowHeight = 100;
