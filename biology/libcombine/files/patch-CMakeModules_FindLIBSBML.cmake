--- CMakeModules/FindLIBSBML.cmake.orig	2022-10-21 06:11:59 UTC
+++ CMakeModules/FindLIBSBML.cmake
@@ -124,9 +124,7 @@ endif (NOT LIBSBML_INCLUDE_DIR)
 
 
 find_library(LIBSBML_LIBRARY 
-    NAMES sbml-static 
-          sbml
-          libsbml-static 
+    NAMES sbml
           libsbml
     PATHS $ENV{LIBSBML_DIR}/lib
           $ENV{LIBSBML_DIR}
@@ -144,8 +142,7 @@ find_library(LIBSBML_LIBRARY 
 
 if (NOT LIBSBML_LIBRARY)
     find_library(LIBSBML_LIBRARY 
-        NAMES sbml-static 
-              sbml)
+        NAMES sbml)
 endif (NOT LIBSBML_LIBRARY)
 
 if (NOT LIBSBML_LIBRARY)
