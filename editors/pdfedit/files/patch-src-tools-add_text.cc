--- src/tools/add_text.cc.orig	2016-06-12 03:53:24.278803000 +0900
+++ src/tools/add_text.cc	2016-06-12 03:53:43.440512000 +0900
@@ -54,7 +54,7 @@
 	};
 
 	struct _add {
-		void operator () (shared_ptr<CPage> page, 
+		void operator () (boost::shared_ptr<CPage> page, 
 						  const string& what, 
 						  const Position& where, 
 						  std::string font_id)
@@ -126,14 +126,14 @@
 				return 1;
 
 		// open pdf
-		shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
+		boost::shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
 
 		if (pdf->isLinearized())
 		{
 			pdf.reset ();
 			string out (file+"-delinearised.pdf");
 			{
-				shared_ptr<Delinearizator> del (Delinearizator::getInstance(file.c_str(), new OldStylePdfWriter));
+				boost::shared_ptr<Delinearizator> del (Delinearizator::getInstance(file.c_str(), new OldStylePdfWriter));
 					if (!del) return -1;
 				del->delinearize(out.c_str());
 			}
@@ -154,7 +154,7 @@
 					continue;
 				}
 
-			shared_ptr<CPage> page = pdf->getPage(*it);
+			boost::shared_ptr<CPage> page = pdf->getPage(*it);
 			_add()(page, what, pos, font_id);
 
 			#ifdef WIN32
