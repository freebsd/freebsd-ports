--- cMake/FreeCAD_Helpers/SetupSalomeSMESH.cmake.orig	2021-04-15 09:17:08 UTC
+++ cMake/FreeCAD_Helpers/SetupSalomeSMESH.cmake
@@ -12,24 +12,24 @@ macro(SetupSalomeSMESH)
 
         #if we use smesh we definitely also need vtk, no matter of external or internal smesh
         set (VTK_COMPONENTS
-            vtkCommonCore
-            vtkCommonDataModel
-            vtkFiltersVerdict
-            vtkIOXML
-            vtkFiltersCore
-            vtkFiltersGeneral
-            vtkIOLegacy
-            vtkFiltersExtraction
-            vtkFiltersSources
-            vtkFiltersGeometry
+            CommonCore
+            tkCommonDataModel
+            tkFiltersVerdict
+            tkIOXML
+            tkFiltersCore
+            tkFiltersGeneral
+            tkIOLegacy
+            tkFiltersExtraction
+            tkFiltersSources
+            tkFiltersGeometry
         )
 
         # check which modules are available
         if(UNIX OR WIN32)
-            find_package(VTK COMPONENTS vtkCommonCore REQUIRED NO_MODULE)
-            list(APPEND VTK_COMPONENTS vtkIOMPIParallel vtkParallelMPI vtkhdf5 vtkFiltersParallelDIY2 vtkRenderingCore vtkInteractionStyle vtkRenderingFreeType vtkRenderingOpenGL2)
+            find_package(VTK COMPONENTS CommonCore REQUIRED NO_MODULE)
+            list(APPEND VTK_COMPONENTS IOMPIParallel ParallelMPI hdf5 FiltersParallelDIY2 RenderingCore InteractionStyle RenderingFreeType RenderingOpenGL2)
             foreach(_module ${VTK_COMPONENTS})
-                list (FIND VTK_MODULES_ENABLED ${_module} _index)
+                list (FIND VTK_AVAILABLE_COMPONENTS ${_module} _index)
                 if (${_index} GREATER -1)
                     list(APPEND AVAILABLE_VTK_COMPONENTS ${_module})
                 endif()
