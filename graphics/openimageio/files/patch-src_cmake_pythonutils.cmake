--- src/cmake/pythonutils.cmake.orig	2026-10-13 19:45:00 UTC
+++ src/cmake/pythonutils.cmake
@@ -258,6 +258,13 @@ macro (setup_python_module_nanobind)
         target_compile_options (nanobind-static PRIVATE -Wno-format-nonliteral)
     endif ()
 
+    # Keep the headers from the selected nanobind package ahead of broad
+    # include paths like /usr/local/include, which may contain a different
+    # nanobind version.
+    if (NB_DIR)
+        target_include_directories (${target_name}
+                                    BEFORE PRIVATE ${NB_DIR}/include)
+    endif ()
     target_include_directories (${target_name}
                                 PRIVATE ${lib_INCLUDES})
     target_include_directories (${target_name}
