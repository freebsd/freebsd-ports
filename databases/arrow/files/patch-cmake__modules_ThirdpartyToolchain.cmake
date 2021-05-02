--- cmake_modules/ThirdpartyToolchain.cmake.orig	2021-04-21 16:14:36 UTC
+++ cmake_modules/ThirdpartyToolchain.cmake
@@ -16,6 +16,7 @@
 # under the License.
 
 include(ProcessorCount)
+include(ExternalProject)
 processorcount(NPROC)
 
 add_custom_target(rapidjson)
@@ -2320,10 +2321,10 @@ macro(build_cares)
   file(MAKE_DIRECTORY ${CARES_INCLUDE_DIR})
 
   add_dependencies(toolchain cares_ep)
-  add_library(c-ares::cares STATIC IMPORTED)
-  set_target_properties(c-ares::cares
-                        PROPERTIES IMPORTED_LOCATION "${CARES_STATIC_LIB}"
-                                   INTERFACE_INCLUDE_DIRECTORIES "${CARES_INCLUDE_DIR}")
+  # add_library(c-ares::cares STATIC IMPORTED)
+  # set_target_properties(c-ares::cares
+  #                       PROPERTIES IMPORTED_LOCATION "${CARES_STATIC_LIB}"
+  #                                  INTERFACE_INCLUDE_DIRECTORIES "${CARES_INCLUDE_DIR}")
   add_dependencies(c-ares::cares cares_ep)
 
   if(APPLE)
@@ -2904,6 +2905,7 @@ if(ARROW_S3)
     set(BUILD_SHARED_LIBS "ON")
   endif()
 
+  set(BUILD_SHARED_LIBS ON)
   # Need to customize the find_package() call, so cannot call resolve_dependency()
   if(AWSSDK_SOURCE STREQUAL "AUTO")
     find_package(AWSSDK
