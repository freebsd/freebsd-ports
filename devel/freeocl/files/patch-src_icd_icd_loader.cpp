--- src/icd/icd_loader.cpp.orig	2012-09-22 13:14:12.000000000 +0400
+++ src/icd/icd_loader.cpp	2012-09-22 13:15:03.000000000 +0400
@@ -53,8 +53,8 @@ namespace FreeOCL
 
 	icd_loader::icd_loader()
 	{
-		// Get the list of all *.icd files in /etc/OpenCL/vendors/
-		const std::deque<std::string> &files = list_files("/etc/OpenCL/vendors/", ".icd");
+		// Get the list of all *.icd files in %%PREFIX%%/etc/OpenCL/vendors/
+		const std::deque<std::string> &files = list_files("%%PREFIX%%/etc/OpenCL/vendors/", ".icd");
 		// For each file
 		for(std::deque<std::string>::const_iterator i = files.begin() ; i != files.end() ; ++i)
 		{
