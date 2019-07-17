--- cmake/GoogleCloudCppCommon.cmake.orig	2019-07-11 02:46:50 UTC
+++ cmake/GoogleCloudCppCommon.cmake
@@ -24,7 +24,6 @@ include(CheckCXXCompilerFlag)
 if (NOT MSVC)
     check_cxx_compiler_flag(-Wall GOOGLE_CLOUD_CPP_COMPILER_SUPPORTS_WALL)
     check_cxx_compiler_flag(-Wextra GOOGLE_CLOUD_CPP_COMPILER_SUPPORTS_WEXTRA)
-    check_cxx_compiler_flag(-Werror GOOGLE_CLOUD_CPP_COMPILER_SUPPORTS_WERROR)
 else()
     check_cxx_compiler_flag("/std:c++latest"
                             GOOGLE_CLOUD_CPP_COMPILER_SUPPORTS_CPP_LATEST)
@@ -118,9 +117,6 @@ function (google_cloud_cpp_add_common_options target)
     endif ()
     if (GOOGLE_CLOUD_CPP_COMPILER_SUPPORTS_WEXTRA)
         target_compile_options(${target} INTERFACE "-Wextra")
-    endif ()
-    if (GOOGLE_CLOUD_CPP_COMPILER_SUPPORTS_WERROR)
-        target_compile_options(${target} INTERFACE "-Werror")
     endif ()
     if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU"
         AND "${CMAKE_CXX_COMPILER_VERSION}" VERSION_LESS 5.0)
