--- cmake_modules/ThirdpartyToolchain.cmake.orig	2024-07-11 08:58:17 UTC
+++ cmake_modules/ThirdpartyToolchain.cmake
@@ -16,6 +16,7 @@ include(ProcessorCount)
 # under the License.
 
 include(ProcessorCount)
+include(ExternalProject)
 processorcount(NPROC)
 
 # Accumulate all bundled targets and we will splice them together later as
@@ -5487,3 +5488,5 @@ message(STATUS "All bundled static libraries: ${ARROW_
 endif()
 
 message(STATUS "All bundled static libraries: ${ARROW_BUNDLED_STATIC_LIBS}")
+
+set(BUILD_SHARED_LIBS ON)
