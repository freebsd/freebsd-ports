--- cmake/modules/SearchInstalledSoftware.cmake.orig	2024-11-30 13:10:36 UTC
+++ cmake/modules/SearchInstalledSoftware.cmake
@@ -525,6 +525,9 @@ if(asimage)
     if(builtin_zlib)
       set(_after_cflags "${_after_cflags} -I${ZLIB_INCLUDE_DIR}")
     endif()
+    if(CMAKE_SYSTEM_NAME MATCHES FreeBSD)
+      set(AFTERIMAGE_LIBRARIES ${CMAKE_BINARY_DIR}/AFTERIMAGE-prefix/src/AFTERIMAGE/libAfterImage${CMAKE_STATIC_LIBRARY_SUFFIX})
+    endif()
     ExternalProject_Add(
       AFTERIMAGE
       DOWNLOAD_COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/graf2d/asimage/src/libAfterImage AFTERIMAGE
@@ -541,6 +544,9 @@ if(asimage)
       TIMEOUT 600
     )
     set(AFTERIMAGE_INCLUDE_DIR ${CMAKE_BINARY_DIR}/include/libAfterImage)
+    if(CMAKE_SYSTEM_NAME MATCHES FreeBSD)
+      set(AFTERIMAGE_INCLUDE_DIR ${CMAKE_BINARY_DIR}/AFTERIMAGE-prefix/src/AFTERIMAGE)
+    endif()
   endif()
   if(builtin_freetype)
     add_dependencies(AFTERIMAGE FREETYPE)
