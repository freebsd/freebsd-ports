--- CMake/FindLibDwarf.cmake.orig	2013-07-12 20:00:55.000000000 +0200
+++ CMake/FindLibDwarf.cmake	2013-07-21 16:31:25.292419225 +0200
@@ -16,31 +16,8 @@
   set (LibDwarf_FIND_QUIETLY TRUE)
 endif (LIBDWARF_LIBRARIES AND LIBDWARF_INCLUDE_DIRS)
 
-find_path (DWARF_INCLUDE_DIR
-    NAMES
-      dwarf.h
-    PATHS
-      /usr/include
-      /usr/include/libdwarf
-      /usr/local/include
-      /opt/local/include
-      /sw/include
-      ENV CPATH) # PATH and INCLUDE will also work
-
-if (DWARF_INCLUDE_DIR)
-    set (LIBDWARF_INCLUDE_DIRS  ${DWARF_INCLUDE_DIR})
-endif ()
-
-find_library (LIBDWARF_LIBRARIES
-    NAMES
-      dwarf
-    PATHS
-      /usr/lib
-      /usr/local/lib
-      /opt/local/lib
-      /sw/lib
-      ENV LIBRARY_PATH   # PATH and LIB will also work
-      ENV LD_LIBRARY_PATH)
+set (LIBDWARF_INCLUDE_DIRS  %%LOCALBASE%%/include)
+set (LIBDWARF_LIBRARIES %%LOCALBASE%%/lib/libdwarf.a)
 include (FindPackageHandleStandardArgs)
 
 
