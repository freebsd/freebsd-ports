--- cmake/FindSDL2test.cmake.orig	2022-07-08 13:31:48 UTC
+++ cmake/FindSDL2test.cmake
@@ -16,6 +16,7 @@ find_package_handle_standard_args(SDL2test
 if(SDL2test_FOUND)
     if(NOT TARGET SDL2::SDL2test)
         add_library(SDL2::SDL2test UNKNOWN IMPORTED)
+        target_link_libraries(SDL2::SDL2test INTERFACE $ENV{LOCALBASE}/lib/libunwind.so)
         set_target_properties(SDL2::SDL2test PROPERTIES
             IMPORTED_LINK_INTERFACE_LANGUAGES "C"
             IMPORTED_LOCATION "${SDL2_TEST_LIBRARY}"
