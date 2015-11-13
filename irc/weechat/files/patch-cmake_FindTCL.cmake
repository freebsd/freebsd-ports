--- cmake/FindTCL.cmake.orig	2015-01-12 09:49:31.591454833 +0000
+++ cmake/FindTCL.cmake	2015-01-12 09:52:04.595540774 +0000
@@ -55,97 +55,18 @@
   set(TCL_FIND_QUIETLY TRUE)
 endif()
 
-include(CMakeFindFrameworks)
-include(FindTclsh)
-
-get_filename_component(TCL_TCLSH_PATH "${TCL_TCLSH}" PATH)
-get_filename_component(TCL_TCLSH_PATH_PARENT "${TCL_TCLSH_PATH}" PATH)
-string(REGEX REPLACE
-  "^.*tclsh([0-9]\\.*[0-9]).*$" "\\1" TCL_TCLSH_VERSION "${TCL_TCLSH}")
-
-get_filename_component(TCL_INCLUDE_PATH_PARENT "${TCL_INCLUDE_PATH}" PATH)
-
-get_filename_component(TCL_LIBRARY_PATH "${TCL_LIBRARY}" PATH)
-get_filename_component(TCL_LIBRARY_PATH_PARENT "${TCL_LIBRARY_PATH}" PATH)
-string(REGEX REPLACE
-  "^.*tcl([0-9]\\.*[0-9]).*$" "\\1" TCL_VERSION "${TCL_LIBRARY}")
-
-set(TCL_POSSIBLE_LIB_PATHS
-  "${TCL_INCLUDE_PATH_PARENT}/lib"
-  "${TCL_INCLUDE_PATH_PARENT}/lib64"
-  "${TCL_LIBRARY_PATH}"
-  "${TCL_TCLSH_PATH_PARENT}/lib"
-  "${TCL_TCLSH_PATH_PARENT}/lib64"
-  /usr/lib
-  /usr/lib64
-  /usr/local/lib
-  /usr/local/lib64
-  )
-
-if(WIN32)
-  get_filename_component(
-    ActiveTcl_CurrentVersion
-    "[HKEY_LOCAL_MACHINE\\SOFTWARE\\ActiveState\\ActiveTcl;CurrentVersion]"
-    NAME)
-  set(TCLTK_POSSIBLE_LIB_PATHS ${TCLTK_POSSIBLE_LIB_PATHS}
-    "[HKEY_LOCAL_MACHINE\\SOFTWARE\\ActiveState\\ActiveTcl\\${ActiveTcl_CurrentVersion}]/lib"
-    "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Scriptics\\Tcl\\8.6;Root]/lib"
-    "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Scriptics\\Tcl\\8.5;Root]/lib"
-    "$ENV{ProgramFiles}/Tcl/Lib"
-    "C:/Program Files/Tcl/lib"
-    "C:/Tcl/lib"
-    )
-endif()
+SET(TCL_VERSION ${BSD_TCL_VER})
+STRING(REPLACE "." "" TCL_INT_VERSION ${TCL_VERSION})
 
 find_library(TCL_LIBRARY
   NAMES
-  tcl86 tcl8.6
-  tcl85 tcl8.5
-  tcl
-  tcl${TCL_VERSION} tcl${TCL_TCLSH_VERSION}
-  PATHS ${TCL_POSSIBLE_LIB_PATHS}
+  tcl${TCL_INT_VERSION}
+  PATHS ${BSD_TCL_LIBDIR}
   )
 
-cmake_find_frameworks(Tcl)
-
-set(TCL_FRAMEWORK_INCLUDES)
-if(Tcl_FRAMEWORKS)
-  if(NOT TCL_INCLUDE_PATH)
-    foreach(dir ${Tcl_FRAMEWORKS})
-      set(TCL_FRAMEWORK_INCLUDES ${TCL_FRAMEWORK_INCLUDES} ${dir}/Headers)
-    endforeach(dir)
-  endif()
-endif()
-
-set(TCL_POSSIBLE_INCLUDE_PATHS
-  "${TCL_LIBRARY_PATH_PARENT}/include"
-  "${TCL_INCLUDE_PATH}"
-  ${TCL_FRAMEWORK_INCLUDES}
-  "${TCL_TCLSH_PATH_PARENT}/include"
-  /usr/include/tcl8.6
-  /usr/include/tcl8.5
-  /usr/include
-  /usr/local/include
-  /usr/include/tcl${TCL_VERSION}
-  /usr/local/include/tcl${TCL_VERSION}
-  /usr/local/include/tcl8.6
-  /usr/local/include/tcl8.5
-  )
-
-if(WIN32)
-  set(TCLTK_POSSIBLE_INCLUDE_PATHS ${TCLTK_POSSIBLE_INCLUDE_PATHS}
-    "[HKEY_LOCAL_MACHINE\\SOFTWARE\\ActiveState\\ActiveTcl\\${ActiveTcl_CurrentVersion}]/include"
-    "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Scriptics\\Tcl\\8.6;Root]/include"
-    "[HKEY_LOCAL_MACHINE\\SOFTWARE\\Scriptics\\Tcl\\8.5;Root]/include"
-    "$ENV{ProgramFiles}/Tcl/include"
-    "C:/Program Files/Tcl/include"
-    "C:/Tcl/include"
-    )
-endif()
-
 find_path(TCL_INCLUDE_PATH
   NAMES tcl.h
-  PATHS ${TCL_POSSIBLE_INCLUDE_PATHS}
+  PATHS ${BSD_TCL_INCDIR}
   )
 
 if(TCL_LIBRARY AND TCL_INCLUDE_PATH)
