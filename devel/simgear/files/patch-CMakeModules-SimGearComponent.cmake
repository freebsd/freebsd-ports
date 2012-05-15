--- CMakeModules/SimGearComponent.cmake.orig	2012-02-17 23:38:44.620896000 +0100
+++ CMakeModules/SimGearComponent.cmake	2012-05-15 07:45:27.783988374 +0200
@@ -1,4 +1,6 @@
 
+include_directories(BEFORE ${PROJECT_SOURCE_DIR})
+
 macro(simgear_component_common name includePath sourcesList sources headers)
     if (SIMGEAR_SHARED)
 
