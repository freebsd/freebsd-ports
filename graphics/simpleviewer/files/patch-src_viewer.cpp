--- src/viewer.cpp.orig	2017-02-23 18:44:09 UTC
+++ src/viewer.cpp
@@ -345,6 +345,7 @@ void cViewer::fnKeyboard(int key, int /*
     switch (key)
     {
     case GLFW_KEY_ESCAPE:
+    case GLFW_KEY_Q:
         glfwSetWindowShouldClose(cRenderer::getWindow(), 1);
         break;
 
