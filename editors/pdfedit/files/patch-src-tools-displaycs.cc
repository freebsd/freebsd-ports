--- src/tools/displaycs.cc.orig	2010-02-23 18:28:09 UTC
+++ src/tools/displaycs.cc
@@ -74,7 +74,7 @@ int main(int argc, char ** argv)
 	size_t from = vm["from"].as<size_t>();
 
 	// open pdf
-	shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
+	boost::shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
 
 	// sane values
 	size_t to = pdf->getPageCount()+1;
@@ -90,8 +90,8 @@ int main(int argc, char ** argv)
 	{
 		std::cout << "=====================" << endl;
 		std::cout << "PAGE NUMBER " << i << endl;
-		shared_ptr<CPage> page = pdf->getPage(i);
-		typedef vector<shared_ptr<CContentStream> > CCs;
+		boost::shared_ptr<CPage> page = pdf->getPage(i);
+		typedef vector<boost::shared_ptr<CContentStream> > CCs;
 		CCs ccs;
 		page->getContentStreams (ccs);
 		std::cout << "- parsed" << endl;
