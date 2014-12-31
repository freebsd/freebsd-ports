------------------------------------------------------------------------
r60023 | starseeker | 2014-03-01 16:23:14 +0200 (Sat, 01 Mar 2014) | 1 line

Get us ready for CMake 3.0 - either fix issues or (mostly) quiet warnings related to new policy rules from CMake 3.0.  The LOCATION property is used fairly extensively, so that's going to be a bit of a trick to avoid.  Not clear yet what a 'correct' approach would be.  Fortunately, if we set that policy to OLD we can carry on.
------------------------------------------------------------------------
--- src/other/perplex/CMakeLists.txt
+++ src/other/perplex/CMakeLists.txt
@@ -37,6 +37,9 @@
 CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 IF(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+    CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 ENDIF(COMMAND CMAKE_POLICY)
 
 PROJECT(PERPLEX)
--- src/other/libvds/CMakeLists.txt
+++ src/other/libvds/CMakeLists.txt
@@ -28,9 +28,12 @@
 if(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
   CMAKE_POLICY(SET CMP0007 OLD)
-  if(${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION} VERSION_GREATER 2.8.3)
+  if("${CMAKE_VERSION}" VERSION_GREATER 2.8.3)
     CMAKE_POLICY(SET CMP0017 OLD)
-  endif(${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION} VERSION_GREATER 2.8.3)
+  endif("${CMAKE_VERSION}" VERSION_GREATER 2.8.3)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+    CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 endif(COMMAND CMAKE_POLICY)
 
 # set CMake project name
--- src/other/tkpng/CMakeLists.txt
+++ src/other/tkpng/CMakeLists.txt
@@ -2,6 +2,9 @@
 CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 IF(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+	  CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 ENDIF(COMMAND CMAKE_POLICY)
 
 # set CMake project name
--- src/other/poly2tri/CMakeLists.txt
+++ src/other/poly2tri/CMakeLists.txt
@@ -2,6 +2,9 @@
 CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 if(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+    CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 endif(COMMAND CMAKE_POLICY)
 
 # Set CMake project name
--- src/other/libtermlib/CMakeLists.txt
+++ src/other/libtermlib/CMakeLists.txt
@@ -1,6 +1,9 @@
 CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 IF(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+    CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 ENDIF(COMMAND CMAKE_POLICY)
 
 PROJECT(LIBTERMLIB)
--- src/other/URToolkit/CMakeLists.txt
+++ src/other/URToolkit/CMakeLists.txt
@@ -1,3 +1,9 @@
+IF(COMMAND CMAKE_POLICY)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+	  CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+ENDIF(COMMAND CMAKE_POLICY)
+
 IF(NOT MSVC)
   MACRO(URT_EXEC execname srcs)
     STRING(REGEX REPLACE " " ";" srcslist "${srcs}")
--- src/other/clipper/CMakeLists.txt
+++ src/other/clipper/CMakeLists.txt
@@ -2,6 +2,9 @@
 CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 IF(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+	  CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 ENDIF(COMMAND CMAKE_POLICY)
 
 # Set CMake project name
--- src/other/lemon/CMakeLists.txt
+++ src/other/lemon/CMakeLists.txt
@@ -2,6 +2,9 @@
 CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 IF(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+    CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 ENDIF(COMMAND CMAKE_POLICY)
 
 # Set CMake project name
--- src/other/openNURBS/CMakeLists.txt
+++ src/other/openNURBS/CMakeLists.txt
@@ -1,3 +1,9 @@
+IF(COMMAND CMAKE_POLICY)
+	if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+		CMAKE_POLICY(SET CMP0026 OLD)
+	endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+ENDIF(COMMAND CMAKE_POLICY)
+
 # build shared libs by default
 IF(NOT DEFINED BUILD_SHARED_LIBS)
   set(BUILD_SHARED_LIBS ON)
--- src/other/tk/CMakeLists.txt
+++ src/other/tk/CMakeLists.txt
@@ -40,6 +40,9 @@
 CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 IF(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+	  CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 ENDIF(COMMAND CMAKE_POLICY)
 
 # set CMake project name
--- src/other/xmltools/CMakeLists.txt
+++ src/other/xmltools/CMakeLists.txt
@@ -2,6 +2,9 @@
 CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 IF(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+	  CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 ENDIF(COMMAND CMAKE_POLICY)
 
 # Set CMake project name
--- src/other/tcl/CMakeLists.txt
+++ src/other/tcl/CMakeLists.txt
@@ -40,6 +40,10 @@
 CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 IF(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+	  CMAKE_POLICY(SET CMP0026 OLD)
+	  CMAKE_POLICY(SET CMP0048 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 ENDIF(COMMAND CMAKE_POLICY)
 
 # Set CMake project name
--- src/other/tktable/CMakeLists.txt
+++ src/other/tktable/CMakeLists.txt
@@ -2,6 +2,9 @@
 CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 IF(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+	  CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 ENDIF(COMMAND CMAKE_POLICY)
 
 # set CMake project name
--- src/other/libutahrle/CMakeLists.txt
+++ src/other/libutahrle/CMakeLists.txt
@@ -1,3 +1,9 @@
+IF(COMMAND CMAKE_POLICY)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+	CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+ENDIF(COMMAND CMAKE_POLICY)
+
 SET(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/CMake")
 INCLUDE(UTAH_CheckFunctions)
 
--- src/other/re2c/CMakeLists.txt
+++ src/other/re2c/CMakeLists.txt
@@ -2,6 +2,9 @@
 CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 if(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+    CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 endif(COMMAND CMAKE_POLICY)
 
 # Set CMake project name
--- src/other/incrTcl/itk/CMakeLists.txt
+++ src/other/incrTcl/itk/CMakeLists.txt
@@ -40,6 +40,10 @@
 CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 IF(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+	  CMAKE_POLICY(SET CMP0026 OLD)
+	  CMAKE_POLICY(SET CMP0048 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 ENDIF(COMMAND CMAKE_POLICY)
 
 # set CMake project name
--- src/other/incrTcl/itcl/CMakeLists.txt
+++ src/other/incrTcl/itcl/CMakeLists.txt
@@ -40,6 +40,10 @@
 CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 IF(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+	  CMAKE_POLICY(SET CMP0026 OLD)
+	  CMAKE_POLICY(SET CMP0048 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 ENDIF(COMMAND CMAKE_POLICY)
 
 # set CMake project name
--- src/other/libz/CMakeLists.txt
+++ src/other/libz/CMakeLists.txt
@@ -1,5 +1,10 @@
 cmake_minimum_required(VERSION 2.4.4)
 set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)
+if(COMMAND CMAKE_POLICY)
+	if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+		CMAKE_POLICY(SET CMP0026 OLD)
+	endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+endif(COMMAND CMAKE_POLICY)
 
 project(zlib C)
 
--- src/other/tkhtml/CMakeLists.txt
+++ src/other/tkhtml/CMakeLists.txt
@@ -2,6 +2,9 @@
 CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
 IF(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+	  CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 ENDIF(COMMAND CMAKE_POLICY)
 
 # set CMake project name
--- src/other/step/CMakeLists.txt
+++ src/other/step/CMakeLists.txt
@@ -54,6 +54,9 @@
 CMAKE_MINIMUM_REQUIRED(VERSION 2.8.7)
 IF(COMMAND CMAKE_POLICY)
   CMAKE_POLICY(SET CMP0003 NEW)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+	  CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 ENDIF(COMMAND CMAKE_POLICY)
 
 IF( NOT DEFINED INCLUDE_INSTALL_DIR )
--- src/other/libpng/CMakeLists.txt
+++ src/other/libpng/CMakeLists.txt
@@ -7,6 +7,12 @@
 # and license in png.h
 
 cmake_minimum_required(VERSION 2.4.4)
+if(COMMAND CMAKE_POLICY)
+	if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+		CMAKE_POLICY(SET CMP0026 OLD)
+	endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+endif(COMMAND CMAKE_POLICY)
+
 set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS true)
 
 set(CMAKE_CONFIGURATION_TYPES "Release;Debug;MinSizeRel;RelWithDebInfo")
@@ -201,6 +207,7 @@
         )
     ADD_CUSTOM_TARGET(${DEST_FILE}_COPY ALL DEPENDS ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${DEST_FILE})
   else(WIN32 AND NOT CYGWIN AND NOT MSYS)
+    file(MAKE_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
     execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${SRC_FILE} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/${DEST_FILE} WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
     execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink ${SRC_FILE} ${DEST_FILE} WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
   endif(WIN32 AND NOT CYGWIN AND NOT MSYS)
--- misc/CMake/Distcheck.cmake
+++ misc/CMake/Distcheck.cmake
@@ -120,8 +120,7 @@
     endif(NOT "${ARGV5}" STREQUAL "")
 
     # If we've already got a particular distcheck target, don't try to create it again.
-    get_target_property(not_in_all distcheck-${TARGET_SUFFIX} EXCLUDE_FROM_ALL)
-    if(NOT not_in_all)
+    if(NOT TARGET distcheck-${TARGET_SUFFIX})
       # Need to set these locally so configure_file will pick them up...
       SET(TARGET_SUFFIX ${TARGET_SUFFIX})
       SET(CMAKE_OPTS ${CMAKE_OPTS})
@@ -155,9 +154,9 @@
 
       # Keep track of the distcheck targets
       set(distcheck_targets ${distcheck_targets} distcheck-${TARGET_SUFFIX})
-    else(NOT not_in_all)
+    else(NOT TARGET distcheck-${TARGET_SUFFIX})
       message(WARNING "Distcheck target distcheck-${TARGET_SUFFIX} already defined, skipping...")
-    endif(NOT not_in_all)
+    endif(NOT TARGET distcheck-${TARGET_SUFFIX})
   endmacro(CREATE_DISTCHECK)
 
   # Top level macro for defining the common "standard" cases and lets a CMake build select either
--- CMakeLists.txt
+++ CMakeLists.txt
@@ -124,6 +124,9 @@
   CMAKE_POLICY(SET CMP0003 NEW)
   CMAKE_POLICY(SET CMP0007 OLD)
   CMAKE_POLICY(SET CMP0017 OLD)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+    CMAKE_POLICY(SET CMP0026 OLD)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 endif(COMMAND CMAKE_POLICY)
 
 # set CMake project name
