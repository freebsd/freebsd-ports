--- src/comet.cpp.orig	Sat May 13 15:48:51 2000
+++ src/comet.cpp	Fri Mar 23 19:49:12 2001
@@ -52,7 +52,7 @@
 #ifdef WIN32
 	wglPointParameterfvEXT(GL_DISTANCE_ATTENUATION_EXT, quad);
 #else
-#ifdef GL_EXT_point_parameters
+#if 0
 	glPointParameterfvEXT(GL_DISTANCE_ATTENUATION_EXT, quad);
 #endif
 #endif
