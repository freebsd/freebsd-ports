--- src/kernel/cpagechanges.cc.orig	2009-04-06 15:24:59 UTC
+++ src/kernel/cpagechanges.cc
@@ -50,7 +50,7 @@ void 
 CPageChanges::displayChange (::OutputDev& out, const Container& cont) const
 {
 
-	shared_ptr<CDict> fakeDict (IProperty::getSmartCObjectPtr<CDict>(_page->getDictionary()->clone()));
+	boost::shared_ptr<CDict> fakeDict (IProperty::getSmartCObjectPtr<CDict>(_page->getDictionary()->clone()));
 		assert (fakeDict);
 
 	CPageContents::setContents (fakeDict, cont);
@@ -66,7 +66,7 @@ CPageChanges::displayChange (::OutputDev
 	// Display page using our dictionary
 	_page->display()->displayPage (out, fakeDict);
 }
-template void CPageChanges::displayChange<vector<shared_ptr<CContentStream> > > (::OutputDev& out, const vector<shared_ptr<CContentStream> >& cont) const;
+template void CPageChanges::displayChange<vector<boost::shared_ptr<CContentStream> > > (::OutputDev& out, const vector<boost::shared_ptr<CContentStream> >& cont) const;
 
 
 //
@@ -87,10 +87,10 @@ CPageChanges::displayChange (::OutputDev
 //
 //
 //
-shared_ptr<CContentStream>
+boost::shared_ptr<CContentStream>
 CPageChanges::getChange (size_t nthchange) const
 {
-	typedef vector<shared_ptr<CContentStream> > CCs;
+	typedef vector<boost::shared_ptr<CContentStream> > CCs;
 	
 	CCs ccs;
 	getChanges (ccs);
@@ -122,9 +122,9 @@ namespace {
 	 */
 	struct ccs_change_sorter 
 	{
-		bool operator() (shared_ptr<CContentStream> frst, shared_ptr<CContentStream> scnd)
+		bool operator() (boost::shared_ptr<CContentStream> frst, boost::shared_ptr<CContentStream> scnd)
 		{
-			typedef vector<shared_ptr<PdfOperator> > Ops;
+			typedef vector<boost::shared_ptr<PdfOperator> > Ops;
 			static const bool FIRST_IS_OUR_LAST = true;
 			static const bool SECOND_IS_OUR_LAST = false;
 			
@@ -163,7 +163,7 @@ CPageChanges::getChanges (Changes& cont)
 	_page->contents()->getContentStreams (ccs);
 	for (CCs::const_iterator it = ccs.begin(); it != ccs.end(); ++it)
 	{
-		vector<shared_ptr<PdfOperator> > ops;
+		vector<boost::shared_ptr<PdfOperator> > ops;
 		(*it)->getPdfOperators (ops);
 			// Empty contentstream is not our change
 			if (ops.empty())
