--- cmake/run_translator.cmake.orig	2015-05-31 21:24:49 UTC
+++ cmake/run_translator.cmake
@@ -1,5 +1,5 @@
 include(${SOURCE}/cmake/version.cmake)
-find_program(PYTHON NAMES python)
+find_package(PythonInterp)
 execute_process(
-    COMMAND ${PYTHON} ${CMAKE_SOURCE_DIR}/translator.py
+    COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_SOURCE_DIR}/translator.py
 )
