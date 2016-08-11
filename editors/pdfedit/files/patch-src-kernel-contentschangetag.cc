--- src/kernel/contentschangetag.cc.orig	2009-07-27 08:18:10 UTC
+++ src/kernel/contentschangetag.cc
@@ -51,11 +51,11 @@ ContentsChangeTag::create ()
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
@@ -72,7 +72,7 @@ ContentsChangeTag::create ()
 //
 //
 time_t
-ContentsChangeTag::getTime (shared_ptr<PdfOperator> op)
+ContentsChangeTag::getTime (boost::shared_ptr<PdfOperator> op)
 {
 	assert (op);
 
