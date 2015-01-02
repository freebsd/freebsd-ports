------------------------------------------------------------------------
r63431 | starseeker | 2014-11-14 13:28:26 +0200 (Fri, 14 Nov 2014) | 1 line

Add INTERFACE to the TARGET_FLAGS list.
------------------------------------------------------------------------
r63433 | starseeker | 2014-11-14 13:54:33 +0200 (Fri, 14 Nov 2014) | 1 line

Work on getting ready for CMake 3.1.  Particularly need to check distcheck with this new setup, with both old and new CMake.  Should investigate CMP0053 issues at some point...
------------------------------------------------------------------------
r63628 | starseeker | 2014-12-09 06:23:04 +0200 (Tue, 09 Dec 2014) | 1 line

More tweaks for new CMake
------------------------------------------------------------------------
--- CMakeLists.txt
+++ CMakeLists.txt
@@ -128,6 +128,10 @@
     CMAKE_POLICY(SET CMP0026 OLD)
     CMAKE_POLICY(SET CMP0042 OLD)
   endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 3.0.9)
+    CMAKE_POLICY(SET CMP0053 OLD)
+    CMAKE_POLICY(SET CMP0054 NEW)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 3.0.9)
 endif(COMMAND CMAKE_POLICY)
 
 # set CMake project name
@@ -394,7 +398,15 @@
     if(${name} MATCHES "^lib*")
       set_target_properties(${name} PROPERTIES PREFIX "")
     endif(${name} MATCHES "^lib*")
-    set_property(GLOBAL APPEND PROPERTY CMAKE_LIBRARY_TARGET_LIST ${name})
+    set(add_lib_to_list 1)
+    foreach(libarg ${ARGN})
+      if("${libarg}" STREQUAL "INTERFACE")
+	set(add_lib_to_list 0)
+      endif("${libarg}" STREQUAL "INTERFACE")
+    endforeach(libarg ${ARGN})
+    if (add_lib_to_list)
+      set_property(GLOBAL APPEND PROPERTY CMAKE_LIBRARY_TARGET_LIST ${name})
+    endif (add_lib_to_list)
   endfunction(add_library)
 
   # Override and wrap add_executable
@@ -1921,16 +1933,10 @@
     list(REMOVE_DUPLICATES CMAKE_EXTERNAL_TARGET_LIST)
   endif(CMAKE_EXTERNAL_TARGET_LIST)
   foreach(libtarget ${CMAKE_LIBRARY_TARGET_LIST})
-    #TODO - can this locate test be replaced with if(TARGET ${libtarget}) ?
-    if(NOT CMAKE_BUILD_TYPE)
-      get_target_property(target_location ${libtarget} LOCATION)
-    else(NOT CMAKE_BUILD_TYPE)
-      get_target_property(target_location ${libtarget} LOCATION_${CMAKE_BUILD_TYPE})
-    endif(NOT CMAKE_BUILD_TYPE)
-    if(target_location)
+    if(TARGET ${libtarget})
       add_dependencies(${libtarget} timestamp)
       add_dependencies(buildtimedelta ${libtarget})
-    endif(target_location)
+    endif(TARGET ${libtarget})
   endforeach(libtarget ${CMAKE_LIBRARY_TARGET_LIST})
   foreach(exectarget ${CMAKE_EXEC_TARGET_LIST})
     if(NOT CMAKE_BUILD_TYPE)
--- misc/CMake/BRLCAD_CMakeFiles.cmake	(revision 63430)
+++ misc/CMake/BRLCAD_CMakeFiles.cmake	(revision 63431)
@@ -65,7 +65,7 @@
       # make sure the file is there.  Normally attempting to ignore
       # a non-existent file is a fatal error, but these keywords
       # don't necessarily refer to files.
-      set(TARGET_FLAGS SHARED STATIC OBJECT WIN32 UNKNOWN IMPORTED)
+      set(TARGET_FLAGS SHARED STATIC OBJECT WIN32 UNKNOWN IMPORTED INTERFACE)
       foreach(TARGET_FLAG ${TARGET_FLAGS})
 	if("${TARGET_FLAG}" STREQUAL "${ITEM}")
 	  if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${ITEM})
--- src/other/libpng/CMakeLists.txt	(revision 63627)
+++ src/other/libpng/CMakeLists.txt	(revision 63628)
@@ -175,11 +181,11 @@
   # does not work with msvc due to png_lib_ver issue
   add_executable(pngtest ${pngtest_sources})
   target_link_libraries(pngtest ${PNG_LIB_NAME})
-  add_test(pngtest ./pngtest ${CMAKE_CURRENT_SOURCE_DIR}/pngtest.png)
+  add_test(pngtest pngtest ${CMAKE_CURRENT_SOURCE_DIR}/pngtest.png)
   #
   add_executable(pngvalid ${pngvalid_sources})
   target_link_libraries(pngvalid ${PNG_LIB_NAME})
-  add_test(pngvalid ./pngvalid)
+  add_test(pngvalid pngvalid)
 endif()
 
 # Ensure the CMAKE_LIBRARY_OUTPUT_DIRECTORY is set
--- src/other/tcl/CMakeLists.txt	(revision 63432)
+++ src/other/tcl/CMakeLists.txt	(revision 63433)
@@ -44,6 +44,10 @@
 	  CMAKE_POLICY(SET CMP0026 OLD)
 	  CMAKE_POLICY(SET CMP0048 OLD)
   endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 3.0.9)
+	  CMAKE_POLICY(SET CMP0053 OLD)
+	  CMAKE_POLICY(SET CMP0054 NEW)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 3.0.9)
 ENDIF(COMMAND CMAKE_POLICY)
 
 # Set CMake project name
--- src/other/tk/CMakeLists.txt	(revision 63432)
+++ src/other/tk/CMakeLists.txt	(revision 63433)
@@ -43,6 +43,9 @@
   if ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
 	  CMAKE_POLICY(SET CMP0026 OLD)
   endif ("${CMAKE_VERSION}" VERSION_GREATER 2.99)
+  if ("${CMAKE_VERSION}" VERSION_GREATER 3.0.9)
+	  CMAKE_POLICY(SET CMP0054 NEW)
+  endif ("${CMAKE_VERSION}" VERSION_GREATER 3.0.9)
 ENDIF(COMMAND CMAKE_POLICY)
 
 # set CMake project name
