--- cmake/defaults/Packages.cmake.orig	2025-10-24 16:21:56 UTC
+++ cmake/defaults/Packages.cmake
@@ -218,6 +218,7 @@ if (PXR_BUILD_IMAGING)
     endif()
     # --Opensubdiv
     set(OPENSUBDIV_USE_GPU ${PXR_BUILD_GPU_SUPPORT})
+    find_package(OpenMP)
     find_package(OpenSubdiv 3 CONFIG)
     if(OpenSubdiv_DIR)
         # Found in CONFIG mode.
@@ -230,6 +231,9 @@ if (PXR_BUILD_IMAGING)
             if(OPENSUBDIV_USE_GPU)
                 list(APPEND OPENSUBDIV_LIBRARIES OpenSubdiv::osdGPU${postfix})
             endif()
+            if(OPENSUBDIV_USE_OPENMP)
+                list(APPEND OPENSUBDIV_LIBRARIES OpenMP::OpenMP_CXX)
+            endif()
             break()
         endforeach()
     endif()
@@ -253,7 +257,7 @@ if (PXR_BUILD_IMAGING)
         add_definitions(-DPXR_OPENVDB_SUPPORT_ENABLED)
     endif()
     # --X11
-    if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
+    if (NOT (CMAKE_SYSTEM_NAME STREQUAL "Darwin" OR CMAKE_SYSTEM_NAME STREQUAL "Windows"))
         find_package(X11)
         add_definitions(-DPXR_X11_SUPPORT_ENABLED)
     endif()
