--- cmake_modules/ThirdpartyToolchain.cmake.orig	2024-03-13 13:37:59 UTC
+++ cmake_modules/ThirdpartyToolchain.cmake
@@ -16,6 +16,7 @@ include(ProcessorCount)
 # under the License.
 
 include(ProcessorCount)
+include(ExternalProject)
 processorcount(NPROC)
 
 add_custom_target(rapidjson)
@@ -5233,6 +5234,8 @@ message(STATUS "All bundled static libraries: ${ARROW_
 endif()
 
 message(STATUS "All bundled static libraries: ${ARROW_BUNDLED_STATIC_LIBS}")
+
+set(BUILD_SHARED_LIBS ON)
 
 # Write out the package configurations.
 
