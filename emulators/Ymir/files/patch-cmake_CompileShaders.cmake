--- cmake/CompileShaders.cmake.orig	2026-10-17 23:19:51 UTC
+++ cmake/CompileShaders.cmake
@@ -72,7 +72,7 @@ endif ()
 endif ()
 
 # SPIR-V is required on systems other than Windows if Vulkan is supported. Bail out if that's not the case.
-if (NOT WIN32 AND Vulkan_FOUND AND NOT DXC_EXECUTABLE)
+if (NOT WIN32 AND Vulkan_FOUND AND NOT DXC_EXECUTABLE AND Ymir_FF_ENABLE_UNIMPL_GFX_BACKENDS)
     message(FATAL_ERROR "Could NOT find a shader compiler supporting SPIR-V. Cannot compile shaders.")
 endif ()
 
