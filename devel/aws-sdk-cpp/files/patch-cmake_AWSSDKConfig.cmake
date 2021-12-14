CMake Error at /usr/local/lib/cmake/AWSSDK/AWSSDKConfig.cmake:132 (while):
  had incorrect arguments:

    "NOT" "TEMP_NAME" "STREQUAL"

  Unknown arguments specified
Call Stack (most recent call first):
  cmake_modules/ThirdpartyToolchain.cmake:4015 (find_package)
  CMakeLists.txt:536 (include)

Obtained from:
    https://github.com/microsoft/vcpkg/commit/148fba1d1a5ec07383aaff4c603c17a1d25399a7


--- cmake/AWSSDKConfig.cmake.orig	2021-12-14 05:48:17 UTC
+++ cmake/AWSSDKConfig.cmake
@@ -129,7 +129,7 @@ endif()
 get_filename_component(TEMP_PATH "${AWSSDK_CORE_LIB_FILE}" PATH)
 get_filename_component(TEMP_NAME "${TEMP_PATH}" NAME)
 
-while (NOT TEMP_NAME STREQUAL ${LIB_SEARCH_PREFIX})
+while (NOT TEMP_NAME STREQUAL "${LIB_SEARCH_PREFIX}")
     set(TEMP_PLATFORM_PREFIX "${TEMP_NAME}/${TEMP_PLATFORM_PREFIX}")
     get_filename_component(TEMP_PATH "${TEMP_PATH}" PATH)
     get_filename_component(TEMP_NAME "${TEMP_PATH}" NAME)
