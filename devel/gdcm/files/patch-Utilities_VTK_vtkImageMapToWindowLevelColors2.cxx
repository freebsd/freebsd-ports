- workaround for https://sourceforge.net/p/gdcm/bugs/536/

--- Utilities/VTK/vtkImageMapToWindowLevelColors2.cxx.orig	2022-06-26 20:39:45 UTC
+++ Utilities/VTK/vtkImageMapToWindowLevelColors2.cxx
@@ -37,6 +37,8 @@
 #include "vtkScalarsToColors.h"
 #include "vtkPointData.h"
 
+#include <math.h>
+
 //vtkCxxRevisionMacro(vtkImageMapToWindowLevelColors2, "$Revision: 1.3 $")
 vtkStandardNewMacro(vtkImageMapToWindowLevelColors2)
 
