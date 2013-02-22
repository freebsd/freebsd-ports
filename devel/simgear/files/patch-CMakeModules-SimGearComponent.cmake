--- CMakeModules/SimGearComponent.cmake.orig	2013-02-21 05:58:12.000000000 +0100
+++ CMakeModules/SimGearComponent.cmake	2013-02-21 05:58:58.000000000 +0100
@@ -1,3 +1,4 @@
+include_directories(BEFORE ${PROJECT_SOURCE_DIR})
 
 macro(simgear_component_common name includePath sourcesList sources headers)
     set(fc${sourcesList} ${name})
