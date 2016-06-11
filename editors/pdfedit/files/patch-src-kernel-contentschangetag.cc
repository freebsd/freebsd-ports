--- src/kernel/contentschangetag.cc.orig	2016-06-12 02:53:06.107246000 +0900
+++ src/kernel/contentschangetag.cc	2016-06-12 02:53:37.952146000 +0900
@@ -51,11 +51,11 @@
 	PdfOperator::Operands opers;
 	
 	// Name or our application
-	shared_ptr<CName> name (new CName (CHANGE_TAG_ID));
+	boost::shared_ptr<CName> name (new CName (CHANGE_TAG_ID));
 	opers.push_back (name);
 	
 	// Dict with our informatio
-	shared_ptr<CDict> dict (new CDict ());
+	boost::shared_ptr<CDict> dict (new CDict ());
 	time_t t = time (NULL);
 	ostringstream oss;
 	oss << t;
@@ -72,7 +72,7 @@
 //
 //
 time_t
-ContentsChangeTag::getTime (shared_ptr<PdfOperator> op)
+ContentsChangeTag::getTime (boost::shared_ptr<PdfOperator> op)
 {
 	assert (op);
 
