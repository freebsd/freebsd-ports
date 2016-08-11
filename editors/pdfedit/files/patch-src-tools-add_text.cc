--- src/tools/add_text.cc.orig	2010-04-30 12:44:31 UTC
+++ src/tools/add_text.cc
@@ -54,7 +54,7 @@ namespace {
 	};
 
 	struct _add {
-		void operator () (shared_ptr<CPage> page, 
+		void operator () (boost::shared_ptr<CPage> page, 
 						  const string& what, 
 						  const Position& where, 
 						  std::string font_id)
@@ -126,14 +126,14 @@ main(int argc, char ** argv)
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
@@ -154,7 +154,7 @@ main(int argc, char ** argv)
 					continue;
 				}
 
-			shared_ptr<CPage> page = pdf->getPage(*it);
+			boost::shared_ptr<CPage> page = pdf->getPage(*it);
 			_add()(page, what, pos, font_id);
 
 			#ifdef WIN32
