--- cmake/FindPython.cmake.orig	2016-01-10 08:17:50 UTC
+++ cmake/FindPython.cmake
@@ -33,17 +33,9 @@ if(PYTHON_FOUND)
    set(PYTHON_FIND_QUIETLY TRUE)
 endif()
 
-if(ENABLE_PYTHON3)
-  find_program(PYTHON_EXECUTABLE
-    NAMES python3.4 python3.3 python3.2 python3.1 python3.0 python3 python2.7 python2.6 python2.5 python
-    PATHS /usr/bin /usr/local/bin /usr/pkg/bin
-    )
-else()
-  find_program(PYTHON_EXECUTABLE
-    NAMES python2.7 python2.6 python2.5 python
-    PATHS /usr/bin /usr/local/bin /usr/pkg/bin
-    )
-endif()
+find_program(PYTHON_EXECUTABLE
+   NAMES ${BSD_PYTHON_CMD}
+   )
 
 if(PYTHON_EXECUTABLE)
   execute_process(
@@ -52,11 +44,6 @@ if(PYTHON_EXECUTABLE)
     )
 
   execute_process(
-    COMMAND ${PYTHON_EXECUTABLE} -c "import sys; from distutils.sysconfig import *; sys.stdout.write(get_config_var('LIBPL'))"
-    OUTPUT_VARIABLE PYTHON_POSSIBLE_LIB_PATH
-    )
-
-  execute_process(
     COMMAND ${PYTHON_EXECUTABLE} -c "import sys; from distutils.sysconfig import *; sys.stdout.write(get_config_var('LINKFORSHARED'))"
     OUTPUT_VARIABLE PYTHON_LFLAGS
     )
@@ -65,32 +52,13 @@ if(PYTHON_EXECUTABLE)
     NAMES Python.h
     HINTS ${PYTHON_INC_DIR}
     )
-  if(ENABLE_PYTHON3)
-    find_library(PYTHON_LIBRARY
-      NAMES python3.4 python3.3 python3.2 python3.1 python3.0 python3 python2.7 python2.6 python2.5 python
-      HINTS ${PYTHON_POSSIBLE_LIB_PATH}
-      )
-  else()
-    find_library(PYTHON_LIBRARY
-      NAMES python2.7 python2.6 python2.5 python
-      HINTS ${PYTHON_POSSIBLE_LIB_PATH}
-      )
-  endif()
+
+  find_library(PYTHON_LIBRARY
+    NAMES ${BSD_PYTHON_VER}
+  	)
 
   if(PYTHON_LIBRARY AND PYTHON_INCLUDE_PATH)
-    execute_process(
-      COMMAND ${PYTHON_EXECUTABLE} -c "import sys; sys.stdout.write(sys.version[:3])"
-      OUTPUT_VARIABLE PYTHON_VERSION
-      )
-    execute_process(
-      COMMAND ${PYTHON_EXECUTABLE} -c "import sys; sys.stdout.write(str(sys.version_info < (2,5)))"
-      OUTPUT_VARIABLE PYTHON_OLD_VERSION
-      )
-    if(${PYTHON_OLD_VERSION} STREQUAL "True")
-      message("Python >= 2.5 is needed to build python plugin, version found: ${PYTHON_VERSION}")
-    else()
-      set(PYTHON_FOUND TRUE)
-    endif()
+    set(PYTHON_FOUND TRUE)
   endif()
 
   mark_as_advanced(
