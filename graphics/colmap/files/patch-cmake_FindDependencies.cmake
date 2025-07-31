--- cmake/FindDependencies.cmake.orig	2025-07-31 15:20:30 UTC
+++ cmake/FindDependencies.cmake
@@ -21,8 +21,7 @@ find_package(Boost ${COLMAP_FIND_TYPE} COMPONENTS
 
 find_package(Boost ${COLMAP_FIND_TYPE} COMPONENTS
              graph
-             program_options
-             system)
+             program_options)
 
 find_package(Eigen3 ${COLMAP_FIND_TYPE})
 
@@ -247,4 +246,4 @@ if(OPENGL_ENABLED OR CUDA_ENABLED)
     list(APPEND COLMAP_COMPILE_DEFINITIONS COLMAP_GPU_ENABLED)
     message(STATUS "Enabling GPU support (OpenGL: ${OPENGL_ENABLED}, CUDA: ${CUDA_ENABLED})")
     set(GPU_ENABLED ON)
-endif()
\ No newline at end of file
+endif()
