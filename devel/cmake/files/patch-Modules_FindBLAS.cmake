When finding BLAS, we may need to explicitly add gcc_s from the correct
gcc directory to the libraries linked in while testing for BLAS functions.
Check for the necessity via some ldd trickery. PR 226959.

--- Modules/FindBLAS.cmake.orig	2018-04-06 14:25:24.441628000 +0200
+++ Modules/FindBLAS.cmake	2018-04-06 15:24:27.515872000 +0200
@@ -162,6 +162,27 @@
   else()
     check_function_exists("${_name}_" ${_prefix}${_combined_name}_WORKS)
   endif()
+  if (NOT ${_prefix}${_combined_name}_WORKS)
+    # On FreeBSD, we may need to link to gcc_s in a special way
+    execute_process(
+        COMMAND /usr/bin/ldd ${${LIBRARIES}}
+        COMMAND /usr/bin/grep gcc_s
+        COMMAND /usr/bin/cut -w -f 4
+        RESULT_VARIABLE _found_needed
+        OUTPUT_VARIABLE _output_needed
+        )
+#    message("DEBUG: found=${_found_needed} output=${_output_needed}")
+    if (_found_needed EQUAL "0" AND _output_needed MATCHES "libgcc_s")
+        set(CMAKE_REQUIRED_LIBRARIES ${_flags} ${${LIBRARIES}} ${_output_needed} ${_thread})
+        message(STATUS "Re-trying ${LIBRARIES} search with gcc_s")
+        if (CMAKE_Fortran_COMPILER_LOADED)
+            check_fortran_function_exists("${_name}" ${_prefix}${_combined_name}_WORKS2)
+        else()
+            check_function_exists("${_name}_" ${_prefix}${_combined_name}_WORKS2)
+        endif()
+        set(${_prefix}${_combined_name}_WORKS ${${_prefix}${_combined_name}_WORKS2})
+    endif()
+  endif()  
   set(CMAKE_REQUIRED_LIBRARIES)
   mark_as_advanced(${_prefix}${_combined_name}_WORKS)
   set(_libraries_work ${${_prefix}${_combined_name}_WORKS})
