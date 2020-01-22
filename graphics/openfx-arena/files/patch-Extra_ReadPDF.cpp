Fix build with poppler 0.83

--- Extra/ReadPDF.cpp.orig	2020-01-18 15:54:18 UTC
+++ Extra/ReadPDF.cpp
@@ -134,7 +134,7 @@ false
     if (!popplerData.empty()) {
         struct stat sb;
         if (stat(popplerData.c_str(), &sb) == 0 && S_ISDIR(sb.st_mode)) {
-            globalParams = new GlobalParams(popplerData.c_str());
+            globalParams = std::unique_ptr<GlobalParams>(new GlobalParams(popplerData.c_str()));
         }
     }
 }
