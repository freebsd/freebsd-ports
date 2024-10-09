--- cmake/LinkerChecks.cmake.orig	2024-09-21 09:08:00 UTC
+++ cmake/LinkerChecks.cmake
@@ -39,7 +39,7 @@ set(CMAKE_REQUIRED_FLAGS_SAVE ${CMAKE_REQUIRED_FLAGS})
 } VERS_1;
 ")
 set(CMAKE_REQUIRED_FLAGS_SAVE ${CMAKE_REQUIRED_FLAGS})
-set(CMAKE_REQUIRED_FLAGS ${CMAKE_REQUIRED_FLAGS} "-Wl,--version-script=${CMAKE_CURRENT_BINARY_DIR}/conftest.map")
+set(CMAKE_REQUIRED_FLAGS ${CMAKE_REQUIRED_FLAGS} -Wl,--undefined-version "-Wl,--version-script=${CMAKE_CURRENT_BINARY_DIR}/conftest.map")
 check_c_source_compiles("int main(void){return 0;}" HAVE_LD_VERSION_SCRIPT)
 set(CMAKE_REQUIRED_FLAGS ${CMAKE_REQUIRED_FLAGS_SAVE})
 file(REMOVE "${CMAKE_CURRENT_BINARY_DIR}/conftest.map")
