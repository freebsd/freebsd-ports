--- cmake/Modules/GrPython.cmake.orig	2019-03-09 13:28:14 UTC
+++ cmake/Modules/GrPython.cmake
@@ -101,11 +101,15 @@ if(NOT DEFINED GR_PYTHON_DIR)
 execute_process(COMMAND ${PYTHON_EXECUTABLE} -c "
 import os
 import sys
-if os.name == 'posix':
-    print(os.path.join('lib', 'python' + sys.version[:3], 'dist-packages'))
-if os.name == 'nt':
-    print(os.path.join('Lib', 'site-packages'))
-" OUTPUT_VARIABLE GR_PYTHON_DIR OUTPUT_STRIP_TRAILING_WHITESPACE
+from sysconfig import get_platform
+if get_platform().startswith('freebsd'):
+        print(os.path.join('lib', 'python' + sys.version[:3], 'site-packages'))
+else:
+    if os.name == 'posix':
+        print(os.path.join('lib', 'python' + sys.version[:3], 'dist-packages'))
+    if os.name == 'nt':
+        print(os.path.join('Lib', 'site-packages'))
+    " OUTPUT_VARIABLE GR_PYTHON_DIR OUTPUT_STRIP_TRAILING_WHITESPACE
 )
 endif()
 file(TO_CMAKE_PATH ${GR_PYTHON_DIR} GR_PYTHON_DIR)
