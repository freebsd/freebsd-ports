--- share/cmake/OCIOMacros.cmake.orig	2015-08-29 00:58:36 UTC
+++ share/cmake/OCIOMacros.cmake
@@ -168,7 +168,7 @@ MACRO(OCIOFindPython)
         file(TO_CMAKE_PATH "${PYTHON_LIBRARY_DIRS_RAW}" PYTHON_LIBRARY_DIRS)
 
         FIND_LIBRARY(PYTHON_LIBRARY
-            NAMES "python${PYTHON_VERSION}"
+            NAMES "${PYTHON_VERSION}${PYTHON_ABIVER}"
             PATHS ${PYTHON_LIBRARY_DIRS}
             NO_DEFAULT_PATH # Don't be "helpful" and randomly grab library from /usr/lib etc
         )
