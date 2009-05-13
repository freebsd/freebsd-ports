--- include/GL/glew.h.orig	2008-11-03 07:25:21.000000000 +0100
+++ include/GL/glew.h	2009-05-04 21:55:35.000000000 +0200
@@ -12243,7 +12243,9 @@
 #ifdef GLEW_APIENTRY_DEFINED
 #undef GLEW_APIENTRY_DEFINED
 #undef APIENTRY
-#undef GLAPIENTRY
+/* Do not undef GLAPIENTRY here. This is a quick hack to avoid
+   undefined symbols when including glut.h just after glew.h */
+/* #undef GLAPIENTRY */
 #endif
 
 #ifdef GLEW_CALLBACK_DEFINED
