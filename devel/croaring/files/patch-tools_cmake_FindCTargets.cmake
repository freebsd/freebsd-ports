--- tools/cmake/FindCTargets.cmake.orig	2026-09-08 23:18:25 UTC
+++ tools/cmake/FindCTargets.cmake
@@ -1,4 +1,7 @@ include(${PROJECT_SOURCE_DIR}/tools/cmake/Import.cmake
 include(${PROJECT_SOURCE_DIR}/tools/cmake/Import.cmake)
+
+find_package(PkgConfig REQUIRED)
+
 set(BUILD_STATIC_LIB ON)
 if (ENABLE_ROARING_TESTS AND NOT EMSCRIPTEN)
   if(ROARING_USE_CPM)
@@ -9,7 +12,7 @@ if (ENABLE_ROARING_TESTS AND NOT EMSCRIPTEN)
       OPTIONS "UNIT_TESTING ON"
     )
   else()
-    find_package(cmocka 2.0.0 REQUIRED)
+    pkg_check_modules(CMOCKA REQUIRED IMPORTED_TARGET cmocka)
   endif()
 endif()
 
@@ -23,7 +26,7 @@ function(add_c_test TEST_NAME)
   if(ROARING_USE_CPM)
     target_link_libraries(${TEST_NAME} roaring cmocka-static)
   else()
-    target_link_libraries(${TEST_NAME} roaring cmocka)
+    target_link_libraries(${TEST_NAME} roaring PkgConfig::CMOCKA)
   endif()
 
   add_test(${TEST_NAME} ${TEST_NAME})
@@ -45,7 +48,8 @@ if (CMAKE_VERSION VERSION_GREATER 2.8.10)
       target_link_libraries(${TEST_NAME} roaring cmocka-static)
       target_include_directories(${TEST_NAME} PRIVATE "${CMAKE_BINARY_DIR}/_deps/cmocka-src/include")
     else()
-      target_link_libraries(${TEST_NAME} roaring cmocka)
+      target_include_directories(${TEST_NAME} PRIVATE "${CMOCKA_INCLUDEDIR}")
+      target_link_libraries(${TEST_NAME} roaring PkgConfig::CMOCKA)
     endif()
 
     add_test(${TEST_NAME} ${TEST_NAME})
