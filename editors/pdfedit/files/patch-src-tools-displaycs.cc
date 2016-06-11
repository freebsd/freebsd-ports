--- src/tools/displaycs.cc.orig	2016-06-12 03:46:15.039573000 +0900
+++ src/tools/displaycs.cc	2016-06-12 03:46:33.669788000 +0900
@@ -74,7 +74,7 @@
 	size_t from = vm["from"].as<size_t>();
 
 	// open pdf
-	shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
+	boost::shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
 
 	// sane values
 	size_t to = pdf->getPageCount()+1;
@@ -90,8 +90,8 @@
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
