--- share/cmake/modules/FindSphinx.cmake.orig	2021-12-05 07:24:43 UTC
+++ share/cmake/modules/FindSphinx.cmake
@@ -24,7 +24,7 @@ endif()
 # Find sphinx-build
 find_program(Sphinx_EXECUTABLE 
     NAMES 
-        sphinx-build
+        sphinx-build-${Python_VERSION_MAJOR}.${Python_VERSION_MINOR}
     HINTS
         ${Sphinx_ROOT}
         ${_Python_SCRIPTS_DIR}
