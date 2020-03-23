--- cmake/FindTCL.cmake.orig	2020-03-16 14:40:15 UTC
+++ cmake/FindTCL.cmake
@@ -22,7 +22,7 @@
 # because there doesn't appear to be a way to override
 # searching OSX system directories before unix directories.
 
-set(TCL_POSSIBLE_NAMES tcl87 tcl8.7
+set(TCL_POSSIBLE_NAMES tcl${FREEBSD_TCL_VER} tcl87 tcl8.7
   tcl86 tcl8.6
   tcl85 tcl8.5
   tcl84 tcl8.4
@@ -67,7 +67,7 @@ get_filename_component(TCL_LIB_PARENT2 "${TCL_LIB_PARE
 # Locate tcl.h
 if (NOT TCL_HEADER)
   find_file(TCL_HEADER tcl.h
-    PATHS ${TCL_LIB_PARENT1} ${TCL_LIB_PARENT2}
+    PATHS ${FREEBSD_TCL_INCLUDEDIR} ${TCL_LIB_PARENT1} ${TCL_LIB_PARENT2}
     PATH_SUFFIXES include include/tcl
     NO_DEFAULT_PATH
     )
