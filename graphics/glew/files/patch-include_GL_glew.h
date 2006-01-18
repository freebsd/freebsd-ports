--- include/GL/glew.h.orig
+++ include/GL/glew.h
@@ -9647,7 +9647,9 @@
 #ifdef GLEW_APIENTRY_DEFINED
 #undef GLEW_APIENTRY_DEFINED
 #undef APIENTRY
-#undef GLAPIENTRY
+/* Do not undef GLAPIENTRY here. This is a quick hack to avoid 
+   undefined symbols when including glut.h just after glew.h */
+/* #undef GLAPIENTRY */
 #endif
 
 #ifdef GLEW_CALLBACK_DEFINED
