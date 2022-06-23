- print glewInit() error description

--- core/src/core.cpp.orig	2022-06-23 16:55:03 UTC
+++ core/src/core.cpp
@@ -383,8 +383,10 @@ int sdrpp_main(int argc, char *argv[]) {
         free(icons[i].pixels);
     }
 
-    if (glewInit() != GLEW_OK) {
+    GLenum err = glewInit();
+    if (err != GLEW_OK) {
         spdlog::error("Failed to initialize OpenGL loader!");
+        spdlog::error(glewGetErrorString(err));
         return 1;
     }
 
