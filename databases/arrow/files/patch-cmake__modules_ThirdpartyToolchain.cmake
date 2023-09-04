--- cmake_modules/ThirdpartyToolchain.cmake.orig	2023-08-17 08:05:04 UTC
+++ cmake_modules/ThirdpartyToolchain.cmake
@@ -16,6 +16,7 @@
 # under the License.
 
 include(ProcessorCount)
+include(ExternalProject)
 processorcount(NPROC)
 
 add_custom_target(rapidjson)
@@ -2046,7 +2047,7 @@ macro(build_gtest)
     string(APPEND GTEST_CMAKE_CXX_FLAGS " -DGTEST_CREATE_SHARED_LIBRARY=1")
   endif()
 
-  set(GTEST_PREFIX "${CMAKE_CURRENT_BINARY_DIR}/googletest_ep-prefix")
+  set(GTEST_PREFIX ${CMAKE_INSTALL_PREFIX})
   set(GTEST_INCLUDE_DIR "${GTEST_PREFIX}/include")
 
   set(_GTEST_LIBRARY_DIR "${GTEST_PREFIX}/lib")
@@ -2087,13 +2088,14 @@ macro(build_gtest)
     list(APPEND GTEST_CMAKE_ARGS -Dgtest_force_shared_crt=ON)
   endif()
 
-  externalproject_add(googletest_ep
-                      ${EP_COMMON_OPTIONS}
-                      URL ${GTEST_SOURCE_URL}
-                      URL_HASH "SHA256=${ARROW_GTEST_BUILD_SHA256_CHECKSUM}"
-                      BUILD_BYPRODUCTS ${GTEST_SHARED_LIB} ${GTEST_MAIN_SHARED_LIB}
-                                       ${GMOCK_SHARED_LIB}
-                      CMAKE_ARGS ${GTEST_CMAKE_ARGS})
+  #externalproject_add(googletest_ep
+  #                    ${EP_COMMON_OPTIONS}
+  #                    URL ${GTEST_SOURCE_URL}
+  #                    URL_HASH "SHA256=${ARROW_GTEST_BUILD_SHA256_CHECKSUM}"
+  #                    BUILD_BYPRODUCTS ${GTEST_SHARED_LIB} ${GTEST_MAIN_SHARED_LIB}
+  #                                     ${GMOCK_SHARED_LIB}
+  #                    CMAKE_ARGS ${GTEST_CMAKE_ARGS})
+  find_package(GTest REQUIRED)
   if(WIN32)
     # Copy the built shared libraries to the same directory as our
     # test programs because Windows doesn't provided rpath (run-time
@@ -2119,16 +2121,16 @@ macro(build_gtest)
     else()
       set(_GTEST_RUNTIME_OUTPUT_DIR ${BUILD_OUTPUT_ROOT_DIRECTORY})
     endif()
-    externalproject_add_step(googletest_ep copy
-                             COMMAND ${CMAKE_COMMAND} -E make_directory
-                                     ${_GTEST_RUNTIME_OUTPUT_DIR}
-                             COMMAND ${CMAKE_COMMAND} -E copy ${_GTEST_RUNTIME_LIB}
-                                     ${_GTEST_RUNTIME_OUTPUT_DIR}
-                             COMMAND ${CMAKE_COMMAND} -E copy ${_GMOCK_RUNTIME_LIB}
-                                     ${_GTEST_RUNTIME_OUTPUT_DIR}
-                             COMMAND ${CMAKE_COMMAND} -E copy ${_GTEST_MAIN_RUNTIME_LIB}
-                                     ${_GTEST_RUNTIME_OUTPUT_DIR}
-                             DEPENDEES install)
+    #externalproject_add_step(googletest_ep copy
+    #                         COMMAND ${CMAKE_COMMAND} -E make_directory
+    #                                 ${_GTEST_RUNTIME_OUTPUT_DIR}
+    #                         COMMAND ${CMAKE_COMMAND} -E copy ${_GTEST_RUNTIME_LIB}
+    #                                 ${_GTEST_RUNTIME_OUTPUT_DIR}
+    #                         COMMAND ${CMAKE_COMMAND} -E copy ${_GMOCK_RUNTIME_LIB}
+    #                                 ${_GTEST_RUNTIME_OUTPUT_DIR}
+    #                         COMMAND ${CMAKE_COMMAND} -E copy ${_GTEST_MAIN_RUNTIME_LIB}
+    #                                 ${_GTEST_RUNTIME_OUTPUT_DIR}
+    #                         DEPENDEES install)
   endif()
 
   # The include directory must exist before it is referenced by a target.
@@ -2152,10 +2154,10 @@ macro(build_gtest)
                                    INTERFACE_COMPILE_DEFINITIONS
                                    "GMOCK_LINKED_AS_SHARED_LIBRARY=1"
                                    INTERFACE_INCLUDE_DIRECTORIES "${GTEST_INCLUDE_DIR}")
-  add_dependencies(toolchain-tests googletest_ep)
-  add_dependencies(arrow::GTest::gtest googletest_ep)
-  add_dependencies(arrow::GTest::gtest_main googletest_ep)
-  add_dependencies(arrow::GTest::gmock googletest_ep)
+  add_dependencies(toolchain-tests GTest::GTest)
+  add_dependencies(arrow::GTest::gtest GTest::GTest)
+  add_dependencies(arrow::GTest::gtest_main GTest::GTest)
+  add_dependencies(arrow::GTest::gmock GTest::GTest)
 endmacro()
 
 if(ARROW_TESTING)
@@ -2703,10 +2705,10 @@ macro(build_cares)
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
@@ -5132,6 +5134,8 @@ if(ARROW_WITH_UCX)
 endif()
 
 message(STATUS "All bundled static libraries: ${ARROW_BUNDLED_STATIC_LIBS}")
+
+set(BUILD_SHARED_LIBS ON)
 
 # Write out the package configurations.
 
