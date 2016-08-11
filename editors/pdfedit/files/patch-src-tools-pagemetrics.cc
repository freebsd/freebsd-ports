--- src/tools/pagemetrics.cc.orig	2010-04-23 06:58:36 UTC
+++ src/tools/pagemetrics.cc
@@ -48,7 +48,7 @@ namespace {
 
 	struct stm {
 		static const string name;
-		void operator () (shared_ptr<CPage> page, P& p)
+		void operator () (boost::shared_ptr<CPage> page, P& p)
 		{
 				if (p.size() < 6) throw std::runtime_error ("too few p params");
 			page->setTransformMatrix (&p[0]);
@@ -58,7 +58,7 @@ namespace {
 	
 	struct sr {
 		static const string name;
-		void operator () (shared_ptr<CPage> page, P& p)
+		void operator () (boost::shared_ptr<CPage> page, P& p)
 		{
 				if (p.size() < 1) throw std::runtime_error ("too few p params");
 			page->setRotation ((int)(p[0]));
@@ -68,7 +68,7 @@ namespace {
 
 	struct smb {
 		static const string name;
-		void operator () (shared_ptr<CPage> page, const P& p)
+		void operator () (boost::shared_ptr<CPage> page, const P& p)
 		{
 				if (p.size() < 4) throw std::runtime_error ("too few p params");
 			page->setMediabox (libs::Rectangle (p[0], p[1], p[2], p[3]));
@@ -131,7 +131,7 @@ main(int argc, char ** argv)
 				return 1;
 
 		// open pdf
-		shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
+		boost::shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
 
 		// sane values
 		to = std::min(to, pdf->getPageCount()+1);
@@ -139,7 +139,7 @@ main(int argc, char ** argv)
 		// now the hard stuff comes
 		for (unsigned int i = from; i < to; ++i)
 		{
-			shared_ptr<CPage> page = pdf->getPage(i);
+			boost::shared_ptr<CPage> page = pdf->getPage(i);
 			if (alg == stm::name)
 				stm()(page,p);
 			else if (alg == sr::name)
