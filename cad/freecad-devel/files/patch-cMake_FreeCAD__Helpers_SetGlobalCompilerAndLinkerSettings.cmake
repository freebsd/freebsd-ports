--- cMake/FreeCAD_Helpers/SetGlobalCompilerAndLinkerSettings.cmake.orig	2025-04-17 06:38:38 UTC
+++ cMake/FreeCAD_Helpers/SetGlobalCompilerAndLinkerSettings.cmake
@@ -103,4 +103,8 @@ macro(SetGlobalCompilerAndLinkerSettings)
         endif()
     endif(MINGW)
 
+# Enable the Topological Naming Problem mitigation code
+add_compile_options(-DFC_USE_TNP_FIX)
+
+
 endmacro(SetGlobalCompilerAndLinkerSettings)
