--- third_party/glfw/src/src/egl_context.c.orig	2022-05-11 07:03:38 UTC
+++ third_party/glfw/src/src/egl_context.c
@@ -712,7 +712,7 @@ GLFWbool _glfwCreateContextEGL(_GLFWwindow* window,
 #elif defined(_GLFW_WIN32)
 #elif defined(_GLFW_COCOA)
 #else
-            "libGL.so.1",
+            "libGL.so",
 #endif
             NULL
         };
