--- cmake/nanobind-config.cmake.orig	2024-12-05 23:06:19 UTC
+++ cmake/nanobind-config.cmake
@@ -166,19 +166,19 @@ function (nanobind_build_library TARGET_NAME)
     ${NB_DIR}/include/nanobind/eigen/dense.h
     ${NB_DIR}/include/nanobind/eigen/sparse.h
 
-    ${NB_DIR}/src/buffer.h
-    ${NB_DIR}/src/hash.h
-    ${NB_DIR}/src/nb_internals.h
-    ${NB_DIR}/src/nb_internals.cpp
-    ${NB_DIR}/src/nb_func.cpp
-    ${NB_DIR}/src/nb_type.cpp
-    ${NB_DIR}/src/nb_enum.cpp
-    ${NB_DIR}/src/nb_ndarray.cpp
-    ${NB_DIR}/src/nb_static_property.cpp
-    ${NB_DIR}/src/common.cpp
-    ${NB_DIR}/src/error.cpp
-    ${NB_DIR}/src/trampoline.cpp
-    ${NB_DIR}/src/implicit.cpp
+    ${NB_DIR}/share/nanobind/src/buffer.h
+    ${NB_DIR}/share/nanobind/src/hash.h
+    ${NB_DIR}/share/nanobind/src/nb_internals.h
+    ${NB_DIR}/share/nanobind/src/nb_internals.cpp
+    ${NB_DIR}/share/nanobind/src/nb_func.cpp
+    ${NB_DIR}/share/nanobind/src/nb_type.cpp
+    ${NB_DIR}/share/nanobind/src/nb_enum.cpp
+    ${NB_DIR}/share/nanobind/src/nb_ndarray.cpp
+    ${NB_DIR}/share/nanobind/src/nb_static_property.cpp
+    ${NB_DIR}/share/nanobind/src/common.cpp
+    ${NB_DIR}/share/nanobind/src/error.cpp
+    ${NB_DIR}/share/nanobind/src/trampoline.cpp
+    ${NB_DIR}/share/nanobind/src/implicit.cpp
   )
 
   if (TARGET_TYPE STREQUAL "SHARED")
@@ -400,8 +400,8 @@ function (nanobind_add_stub name)
 function (nanobind_add_stub name)
   cmake_parse_arguments(PARSE_ARGV 1 ARG "VERBOSE;INCLUDE_PRIVATE;EXCLUDE_DOCSTRINGS;INSTALL_TIME;EXCLUDE_FROM_ALL" "MODULE;OUTPUT;MARKER_FILE;COMPONENT;PATTERN_FILE" "PYTHON_PATH;DEPENDS")
 
-  if (EXISTS ${NB_DIR}/src/stubgen.py)
-    set(NB_STUBGEN "${NB_DIR}/src/stubgen.py")
+  if (EXISTS ${NB_DIR}/share/nanobind/stubgen.py)
+    set(NB_STUBGEN "${NB_DIR}/share/nanobind/stubgen.py")
   elseif (EXISTS ${NB_DIR}/stubgen.py)
     set(NB_STUBGEN "${NB_DIR}/stubgen.py")
   else()
