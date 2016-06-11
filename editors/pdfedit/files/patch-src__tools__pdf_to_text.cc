--- src/tools/pdf_to_text.cc.orig	2010-04-23 15:58:36.000000000 +0900
+++ src/tools/pdf_to_text.cc	2016-06-12 03:51:28.186690000 +0900
@@ -45,8 +45,16 @@
 	};
 	// what to do with a page
 	struct _textify {
-		string operator () (shared_ptr<CPage> page)
+		string operator () (boost::shared_ptr<CPage> page)
 		{
+			// Update display params to use media box not default page rect (DEFAULT_PAGE_RX, DEFAULT_PAGE_RY)
+			// TODO upsidedown? get/set
+			DisplayParams dp;
+			dp.useMediaBox = gTrue;
+			dp.crop = gFalse;
+			dp.rotate = page->getRotation ();
+			page->setDisplayParams (dp);
+
 			string text;
 			static const std::string encoding="UTF-8";
 			page->getText (text, &encoding);
@@ -97,13 +105,13 @@
 				return 1;
 
 		// open pdf
-		shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
+		boost::shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
 
 		if (pages.empty())
 		{
 			for (size_t i = 1; i <= pdf->getPageCount(); ++i)
 			{
-				shared_ptr<CPage> page = pdf->getPage(i);
+				boost::shared_ptr<CPage> page = pdf->getPage(i);
 				std::cout << "\nPage " << i << ":\n" << _textify()(page);
 			}
 		}
@@ -117,7 +125,7 @@
 					continue;
 				}
 
-			shared_ptr<CPage> page = pdf->getPage(*it);
+			boost::shared_ptr<CPage> page = pdf->getPage(*it);
 			std::cout << "\nPage " << *it << ":\n" << _textify()(page);
 		}
 
