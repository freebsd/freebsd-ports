--- source/MaterialXGraphEditor/RenderView.cpp.orig	2025-09-15 18:12:11 UTC
+++ source/MaterialXGraphEditor/RenderView.cpp
@@ -16,6 +16,9 @@
 #include <MaterialXRender/TinyObjLoader.h>
 
 #include <MaterialXGenShader/DefaultColorManagementSystem.h>
+#ifdef MATERIALX_BUILD_OCIO
+#include <MaterialXGenShader/OcioColorManagementSystem.h>
+#endif
 
 #include <MaterialXFormat/Util.h>
 
