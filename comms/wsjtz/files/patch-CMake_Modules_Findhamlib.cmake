--- CMake/Modules/Findhamlib.cmake.orig	2021-02-01 18:08:30 UTC
+++ CMake/Modules/Findhamlib.cmake
@@ -16,7 +16,7 @@ set (hamlib_LIBRARY_DIRS)
 
 # pkg-config?
 find_path (__hamlib_pc_path NAMES hamlib.pc
-  PATH_SUFFIXES lib/pkgconfig lib64/pkgconfig
+  PATH_SUFFIXES libdata/pkgconfig lib64/pkgconfig
   )
 if (__hamlib_pc_path)
   set (__pc_path $ENV{PKG_CONFIG_PATH})
