--- samples/cpp/bagofwords_classification.cpp.orig	2011-09-12 20:20:43.000000000 +0200
+++ samples/cpp/bagofwords_classification.cpp	2013-09-12 14:57:38.068066669 +0200
@@ -1814,7 +1814,7 @@
 void VocData::readFileToString(const string filename, string& file_contents)
 {
     std::ifstream ifs(filename.c_str());
-    if (ifs == false) CV_Error(CV_StsError,"could not open text file");
+    if (!ifs.is_open()) CV_Error(CV_StsError,"could not open text file");
 
     stringstream oss;
     oss << ifs.rdbuf();
