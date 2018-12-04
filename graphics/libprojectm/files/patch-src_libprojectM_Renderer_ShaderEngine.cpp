--- src/libprojectM/Renderer/ShaderEngine.cpp.orig	2018-12-03 11:18:41 UTC
+++ src/libprojectM/Renderer/ShaderEngine.cpp
@@ -16,6 +16,9 @@
 #include <glm/gtc/type_ptr.hpp>
 #include <set>
 #include <regex>
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#endif
 
 #ifdef USE_GLES
     #define GLSL_VERSION "300 es"
