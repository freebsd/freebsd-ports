--- tools/clitkProfileImageGenericFilter.cxx.orig	2026-03-01 23:21:24 UTC
+++ tools/clitkProfileImageGenericFilter.cxx
@@ -35,8 +35,10 @@
 
 #include <clitkCommon.h>
 
+#include <iostream>
 
 
+
 namespace clitk
 {
 
@@ -202,7 +204,7 @@ void ProfileImageGenericFilter::WriteOutput(std::strin
   std::ofstream fileOpen(outputFilename.c_str(), std::ofstream::trunc);
 
   if(!fileOpen) {
-      cerr << "Error during saving" << endl;
+      std::cerr << "Error during saving" << endl;
       return;
   }
 
