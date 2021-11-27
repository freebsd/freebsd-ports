--- CMake/3rd_party_libs.cmake.orig	2019-01-18 18:25:46 UTC
+++ CMake/3rd_party_libs.cmake
@@ -53,7 +53,8 @@ if (BUILD_BENCHMARKS OR BUILD_EXAMPLES)
     find_package(Threads REQUIRED)
 endif()
 
-set(RAPID_JSON_DIR ${RTTR_3RD_PARTY_DIR}/rapidjson-1.1.0)
+find_package(RapidJSON REQUIRED)
+set(RAPID_JSON_DIR ${RapidJSON_INCLUDE_DIR})
 set(NONIUS_DIR ${RTTR_3RD_PARTY_DIR}/nonius-1.1.2)
 
 # Prepare "Catch" library for other executables
@@ -63,7 +64,9 @@ add_library(Catch2::Catch ALIAS Catch)
 target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})
 
 # Find chai script
-set(CHAISCRIPT_INCLUDE_DIR ${RTTR_3RD_PARTY_DIR}/chaiscript-6.1.0)
+find_package(PkgConfig REQUIRED)
+pkg_check_modules(_chaiscript REQUIRED chaiscript)
+set(CHAISCRIPT_INCLUDE_DIR ${_chaiscript_INCLUDEDIR})
 add_library(ChaiScript INTERFACE)
 add_library(ChaiScript::ChaiScript ALIAS ChaiScript)
 target_include_directories(ChaiScript INTERFACE ${CHAISCRIPT_INCLUDE_DIR})
