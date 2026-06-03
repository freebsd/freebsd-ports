--- tools/clitkHistogramImageGenericFilter.cxx.orig	2026-03-01 23:19:15 UTC
+++ tools/clitkHistogramImageGenericFilter.cxx
@@ -35,6 +35,8 @@
 
 #include <clitkCommon.h>
 
+#include <fstream>
+#include <iostream>
 
 
 namespace clitk
@@ -170,16 +172,16 @@ void HistogramImageGenericFilter::SaveAs()
   std::ofstream fileOpen(textFileName.c_str(), std::ofstream::trunc);
 
   if(!fileOpen) {
-      cerr << "Error during saving" << endl;
+      std::cerr << "Error during saving" << std::endl;
       return;
   }
 
   int i(0);
-  fileOpen << "Value represents the number of voxels around the corresponding intensity (by default the windows size around intensity is log(range))" << endl;
-  fileOpen << "Intensity" << "\t" << "Value" << endl;
+  fileOpen << "Value represents the number of voxels around the corresponding intensity (by default the windows size around intensity is log(range))" << std::endl;
+  fileOpen << "Intensity" << "\t" << "Value" << std::endl;
 
   while (i<mArrayX->GetNumberOfTuples()) {
-      fileOpen << mArrayX->GetTuple(i)[0] << "\t" << mArrayY->GetTuple(i)[0] << endl;
+      fileOpen << mArrayX->GetTuple(i)[0] << "\t" << mArrayY->GetTuple(i)[0] << std::endl;
       ++i;
   }
 
