--- src/tools/replace_text.cc.orig	2010-02-23 18:28:09 UTC
+++ src/tools/replace_text.cc
@@ -22,6 +22,7 @@
  * Project is hosted on http://sourceforge.net/projects/pdfedit
  */
 #include <sstream>
+#include <algorithm>
 #include <kernel/pdfedit-core-dev.h>
 #include <kernel/cpdf.h>
 #include <kernel/cpage.h>
@@ -59,7 +60,7 @@ namespace {
 
 	struct _replace {
 		static const string name;
-		void operator () (shared_ptr<CPage> page, const string& what, const string& with)
+		void operator () (boost::shared_ptr<CPage> page, const string& what, const string& with)
 		{
 			page->replaceText (what, with);
 		}
@@ -121,14 +122,14 @@ main(int argc, char ** argv)
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
@@ -137,7 +138,7 @@ main(int argc, char ** argv)
 
 
 		// sane values
-		to = std::min(to, pdf->getPageCount()+1);
+		to = std::min(to, (size_t)(pdf->getPageCount()+1));
 
 		// now the hard stuff comes - do this crazy loops intentionally
 		for (size_t things_to_replace = 0; things_to_replace < withs.size(); ++things_to_replace)
@@ -150,7 +151,7 @@ main(int argc, char ** argv)
 			string with = withs[things_to_replace];
 			for (size_t i = from; i < to; ++i)
 			{
-				shared_ptr<CPage> page = pdf->getPage(i);
+				boost::shared_ptr<CPage> page = pdf->getPage(i);
 				_replace()(page, what, with);
 			}
 			#ifdef WIN32
