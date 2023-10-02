--- cmake/libremidi.tests.cmake.orig	2023-10-02 17:31:54 UTC
+++ cmake/libremidi.tests.cmake
@@ -1,4 +1,4 @@
-
+  if (FALSE)
   include(FetchContent)
 
   FetchContent_Declare(
@@ -8,6 +8,8 @@
   )
 
   FetchContent_MakeAvailable(Catch2)
+  endif()
+  find_package(Catch2)
   if(NOT TARGET Catch2::Catch2WithMain)
     message(WARNING "libremidi: Catch2::Catch2WithMain target not found")
     return()
