--- src/tools/pagemetrics.cc.orig	2016-06-12 03:48:34.337781000 +0900
+++ src/tools/pagemetrics.cc	2016-06-12 03:48:53.651846000 +0900
@@ -48,7 +48,7 @@
 
 	struct stm {
 		static const string name;
-		void operator () (shared_ptr<CPage> page, P& p)
+		void operator () (boost::shared_ptr<CPage> page, P& p)
 		{
 				if (p.size() < 6) throw std::runtime_error ("too few p params");
 			page->setTransformMatrix (&p[0]);
@@ -58,7 +58,7 @@
 	
 	struct sr {
 		static const string name;
-		void operator () (shared_ptr<CPage> page, P& p)
+		void operator () (boost::shared_ptr<CPage> page, P& p)
 		{
 				if (p.size() < 1) throw std::runtime_error ("too few p params");
 			page->setRotation ((int)(p[0]));
@@ -68,7 +68,7 @@
 
 	struct smb {
 		static const string name;
-		void operator () (shared_ptr<CPage> page, const P& p)
+		void operator () (boost::shared_ptr<CPage> page, const P& p)
 		{
 				if (p.size() < 4) throw std::runtime_error ("too few p params");
 			page->setMediabox (libs::Rectangle (p[0], p[1], p[2], p[3]));
@@ -131,7 +131,7 @@
 				return 1;
 
 		// open pdf
-		shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
+		boost::shared_ptr<CPdf> pdf = CPdf::getInstance (file.c_str(), CPdf::ReadWrite);
 
 		// sane values
 		to = std::min(to, pdf->getPageCount()+1);
@@ -139,7 +139,7 @@
 		// now the hard stuff comes
 		for (unsigned int i = from; i < to; ++i)
 		{
-			shared_ptr<CPage> page = pdf->getPage(i);
+			boost::shared_ptr<CPage> page = pdf->getPage(i);
 			if (alg == stm::name)
 				stm()(page,p);
 			else if (alg == sr::name)
