--- libs/tex/io/magicnumber.cpp.orig	2012-02-20 18:01:58.000000000 +0300
+++ libs/tex/io/magicnumber.cpp	2012-02-20 18:02:12.000000000 +0300
@@ -59,7 +59,7 @@
 
 EqImageFileType guessFileType(const boostfs::path& fileName)
 {
-	std::ifstream inFile(fileName.file_string().c_str());
+	std::ifstream inFile(fileName.string().c_str());
 	if(!inFile)
 	{
 		AQSIS_THROW_XQERROR(XqInvalidFile, EqE_NoFile, "Cannot open file \""
