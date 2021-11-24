--- third_party/swiftshader/src/OpenGL/libEGL/Surface.cpp.orig	2021-04-14 01:15:28 UTC
+++ third_party/swiftshader/src/OpenGL/libEGL/Surface.cpp
@@ -357,7 +357,7 @@ bool WindowSurface::checkForResize()
 
 		int windowWidth = windowAttributes.width;
 		int windowHeight = windowAttributes.height;
-	#elif defined(__linux__)
+	#elif defined(__linux__) || defined(__FreeBSD__)
 		// Non X11 linux is headless only
 		int windowWidth = 100;
 		int windowHeight = 100;
