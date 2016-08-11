--- src/tools/pdf_images.cc.orig	2010-04-27 12:25:28 UTC
+++ src/tools/pdf_images.cc
@@ -51,7 +51,7 @@ namespace {
 	};
 	// what to do with a page
 	struct _extract_images {
-		void operator () (shared_ptr<CPage> page, ImageOutputDev& img_out, pdfobjects::DisplayParams& displayparams)
+		void operator () (boost::shared_ptr<CPage> page, ImageOutputDev& img_out, pdfobjects::DisplayParams& displayparams)
 		{
 		    page->displayPage (img_out, displayparams);
 		}
@@ -107,7 +107,7 @@ main(int argc, char ** argv)
 				return 1;
 
 		// open pdf
-		shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
+		boost::shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
 		ImageOutputDev img_out (const_cast<char*> (dir.c_str()), gTrue);
 
 		// alter display params
@@ -119,7 +119,7 @@ main(int argc, char ** argv)
 		{
 			for (size_t i = 1; i <= pdf->getPageCount(); ++i)
 			{
-				shared_ptr<CPage> page = pdf->getPage(i);
+				boost::shared_ptr<CPage> page = pdf->getPage(i);
 				std::cout << "\nPage " << i << ":";
 				_extract_images()(page, img_out, displayparams);
 			}
@@ -134,7 +134,7 @@ main(int argc, char ** argv)
 					continue;
 				}
 
-			shared_ptr<CPage> page = pdf->getPage(*it);
+			boost::shared_ptr<CPage> page = pdf->getPage(*it);
 			std::cout << "\nPage " << *it << ":";
 			_extract_images()(page, img_out, displayparams);
 		}
