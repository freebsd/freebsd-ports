--- cMake/FreeCAD_Helpers/SetupSalomeSMESH.cmake.orig	2022-06-14 23:16:43 +0200
+++ cMake/FreeCAD_Helpers/SetupSalomeSMESH.cmake
@@ -26,7 +26,7 @@
 
         # check which modules are available
         if(UNIX OR WIN32)
-            find_package(VTK COMPONENTS vtkCommonCore REQUIRED NO_MODULE)
+            find_package(VTK COMPONENTS CommonCore REQUIRED NO_MODULE)
             if(${VTK_MAJOR_VERSION} LESS 9)
                 list(APPEND VTK_COMPONENTS vtkIOMPIParallel vtkParallelMPI vtkhdf5 vtkFiltersParallelDIY2 vtkRenderingCore vtkInteractionStyle vtkRenderingFreeType vtkRenderingOpenGL2)
                 foreach(_module ${VTK_COMPONENTS})
