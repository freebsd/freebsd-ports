--- Modules/FindPythonInterp.cmake.orig	2010-11-03 20:58:27.000000000 +0100
+++ Modules/FindPythonInterp.cmake	2010-11-17 10:51:18.700039887 +0100
@@ -20,7 +20,7 @@
 #  License text for the above reference.)
 
 FIND_PROGRAM(PYTHON_EXECUTABLE
-  NAMES python2.7 python2.6 python2.5 python2.4 python2.3 python2.2 python2.1 python2.0 python1.6 python1.5 python
+  NAMES python python2.7 python2.6 python2.5 python2.4 python2.3 python2.2 python2.1 python2.0 python1.6 python1.5
   PATHS
   [HKEY_LOCAL_MACHINE\\SOFTWARE\\Python\\PythonCore\\2.7\\InstallPath]
   [HKEY_LOCAL_MACHINE\\SOFTWARE\\Python\\PythonCore\\2.6\\InstallPath]
