Avoid looking for pthread by simply asserting that it is there.
Otherwise openmp can't be found because the pthread library
lives in /usr/lib and CMake 3.11 doesn't look there anymore
while looking for openmp. PR 223678.

Look for omp.h in LOCALBASE and pass suitable -I and -L flags
if those are necessary. Also use OpenMP flags when linking.
PR 223678 and PR 234050.

--- Modules/FindOpenMP.cmake.orig	2021-03-23 15:43:17 UTC
+++ Modules/FindOpenMP.cmake
@@ -97,6 +97,33 @@ cmake_policy(SET CMP0012 NEW) # if() recognizes number
 cmake_policy(SET CMP0054 NEW) # if() quoted variables not dereferenced
 cmake_policy(SET CMP0057 NEW) # if IN_LIST
 
+set(OpenMP_pthread_LIBRARY -lpthread)
+
+# If the compiler itself has support for OpenMP, then omp.h is hidden
+# away somewhere and it won't be found here; but if the support comes
+# from an external package, it needs to have the right -I and -L flags.
+find_file(_path_to_omp_h omp.h)
+if(NOT _path_to_omp_h)
+  find_file(_path_to_omp_h omp.h
+    HINTS $ENV{LOCALBASE}/include /usr/local/include)
+endif()
+if(_path_to_omp_h)
+  get_filename_component(OpenMP_INCLUDE_DIR ${_path_to_omp_h} DIRECTORY)
+else()
+  set(OpenMP_INCLUDE_DIR "omp_h-NOTFOUND")
+endif()
+
+find_library(_path_to_omp_lib omp)
+if(NOT _path_to_omp_lib)
+  find_library(_path_to_omp_lib omp
+    PATHS $ENV{LOCALBASE}/lib /usr/local/lib)
+endif()
+if(_path_to_omp_lib)
+  get_filename_component(OpenMP_LIB_DIR ${_path_to_omp_lib} DIRECTORY)
+else()
+  set(OpenMP_LIB_DIR "omp_lib-NOTFOUND")
+endif()
+
 function(_OPENMP_FLAG_CANDIDATES LANG)
   if(NOT OpenMP_${LANG}_FLAG)
     unset(OpenMP_FLAG_CANDIDATES)
@@ -210,6 +237,15 @@ function(_OPENMP_GET_FLAGS LANG FLAG_MODE OPENMP_FLAG_
     if(OpenMP_VERBOSE_COMPILE_OPTIONS)
       string(APPEND OPENMP_FLAGS_TEST " ${OpenMP_VERBOSE_COMPILE_OPTIONS}")
     endif()
+    set(_extra_flag "")
+    if(OpenMP_INCLUDE_DIR)
+      string(APPEND _extra_flag " -I${OpenMP_INCLUDE_DIR}")
+    endif()
+    if(OpenMP_LIB_DIR)
+      string(APPEND _extra_flag " -L${OpenMP_LIB_DIR}")
+    endif()
+    set(_need_extra FALSE)
+
     string(REGEX REPLACE "[-/=+]" "" OPENMP_PLAIN_FLAG "${OPENMP_FLAG}")
     try_compile( OpenMP_COMPILE_RESULT_${FLAG_MODE}_${OPENMP_PLAIN_FLAG} ${CMAKE_BINARY_DIR} ${_OPENMP_TEST_SRC}
       CMAKE_FLAGS "-DCOMPILE_DEFINITIONS:STRING=${OPENMP_FLAGS_TEST}"
@@ -217,8 +253,23 @@ function(_OPENMP_GET_FLAGS LANG FLAG_MODE OPENMP_FLAG_
       OUTPUT_VARIABLE OpenMP_TRY_COMPILE_OUTPUT
     )
 
+    # Might need that -I -L after all..
+    if(NOT OpenMP_COMPILE_RESULT_${FLAG_MODE}_${OPENMP_PLAIN_FLAG})
+      unset(OpenMP_COMPILE_RESULT_${FLAG_MODE}_${OPENMP_PLAIN_FLAG})
+      try_compile( OpenMP_COMPILE_RESULT_${FLAG_MODE}_${OPENMP_PLAIN_FLAG} ${CMAKE_BINARY_DIR} ${_OPENMP_TEST_SRC}
+        CMAKE_FLAGS "-DCOMPILE_DEFINITIONS:STRING=${OPENMP_FLAGS_TEST} ${_extra_flag}"
+        LINK_LIBRARIES ${CMAKE_${LANG}_VERBOSE_FLAG}
+        OUTPUT_VARIABLE OpenMP_TRY_COMPILE_OUTPUT
+      )
+      set(_need_extra TRUE)
+    endif()
+
     if(OpenMP_COMPILE_RESULT_${FLAG_MODE}_${OPENMP_PLAIN_FLAG})
-      set("${OPENMP_FLAG_VAR}" "${OPENMP_FLAG}" PARENT_SCOPE)
+      if(_need_extra)
+        set("${OPENMP_FLAG_VAR}" "${OPENMP_FLAG} ${_extra_flag}" PARENT_SCOPE)
+      else()
+        set("${OPENMP_FLAG_VAR}" "${OPENMP_FLAG}" PARENT_SCOPE)
+      endif()
 
       if(CMAKE_${LANG}_VERBOSE_FLAG)
         unset(OpenMP_${LANG}_IMPLICIT_LIBRARIES)
@@ -565,9 +616,16 @@ foreach(LANG IN LISTS OpenMP_FINDLIST)
         add_library(OpenMP::OpenMP_${LANG} INTERFACE IMPORTED)
       endif()
       if(OpenMP_${LANG}_FLAGS)
-        separate_arguments(_OpenMP_${LANG}_OPTIONS NATIVE_COMMAND "${OpenMP_${LANG}_FLAGS}")
+        # All the options except -L..
+        separate_arguments(_OpenMP_${LANG}_COMPILE_OPTIONS NATIVE_COMMAND "${OpenMP_${LANG}_FLAGS}")
+        list(FILTER _OpenMP_${LANG}_COMPILE_OPTIONS EXCLUDE REGEX "^-L/")
+        # All the options except -I..
+        separate_arguments(_OpenMP_${LANG}_LINK_OPTIONS NATIVE_COMMAND "${OpenMP_${LANG}_FLAGS}")
+        list(FILTER _OpenMP_${LANG}_LINK_OPTIONS EXCLUDE REGEX "^-I/")
         set_property(TARGET OpenMP::OpenMP_${LANG} PROPERTY
-          INTERFACE_COMPILE_OPTIONS "$<$<COMPILE_LANGUAGE:${LANG}>:${_OpenMP_${LANG}_OPTIONS}>")
+          INTERFACE_COMPILE_OPTIONS "$<$<COMPILE_LANGUAGE:${LANG}>:${_OpenMP_${LANG}_COMPILE_OPTIONS}>")
+        set_property(TARGET OpenMP::OpenMP_${LANG} PROPERTY
+          INTERFACE_LINK_OPTIONS "$<$<COMPILE_LANGUAGE:${LANG}>:${_OpenMP_${LANG}_LINK_OPTIONS}>")
         unset(_OpenMP_${LANG}_OPTIONS)
       endif()
       if(OpenMP_${LANG}_INCLUDE_DIRS)
