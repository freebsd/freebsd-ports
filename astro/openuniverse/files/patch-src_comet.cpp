--- src/comet.cpp.orig	2000-05-13 22:48:51 UTC
+++ src/comet.cpp
@@ -52,7 +52,7 @@ void CometTail(int body)
 #ifdef WIN32
 	wglPointParameterfvEXT(GL_DISTANCE_ATTENUATION_EXT, quad);
 #else
-#ifdef GL_EXT_point_parameters
+#if 0
 	glPointParameterfvEXT(GL_DISTANCE_ATTENUATION_EXT, quad);
 #endif
 #endif
