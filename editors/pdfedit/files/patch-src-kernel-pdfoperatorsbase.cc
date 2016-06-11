--- src/kernel/pdfoperatorsbase.cc.orig	2009-04-06 15:25:00 UTC
+++ src/kernel/pdfoperatorsbase.cc
@@ -48,7 +48,7 @@ using namespace debug;
 //
 //
 //
-shared_ptr<CContentStream>
+boost::shared_ptr<CContentStream>
 PdfOperator::getContentStream () const
 {
 		assert (_contentstream);
@@ -57,7 +57,7 @@ PdfOperator::getContentStream () const
 }
 	
 void 
-PdfOperator::putBehind (shared_ptr<PdfOperator> behindWhich, shared_ptr<PdfOperator> which)
+PdfOperator::putBehind (boost::shared_ptr<PdfOperator> behindWhich, boost::shared_ptr<PdfOperator> which)
 {
 	if (behindWhich && which)
 	{
@@ -92,7 +92,7 @@ PdfOperator::putBehind (shared_ptr<PdfOp
 //
 //
 void 
-CompositePdfOperator::push_back (const shared_ptr<PdfOperator> oper, shared_ptr<PdfOperator> prev)
+CompositePdfOperator::push_back (const boost::shared_ptr<PdfOperator> oper, boost::shared_ptr<PdfOperator> prev)
 {
 		assert (oper);
 		kernelPrintDbg (debug::DBG_DBG, "");
@@ -136,7 +136,7 @@ CompositePdfOperator::push_back (const s
 //
 //
 void
-CompositePdfOperator::remove (shared_ptr<PdfOperator> op)
+CompositePdfOperator::remove (boost::shared_ptr<PdfOperator> op)
 { 
 	PdfOperators::iterator it =  find (_children.begin(), _children.end(), op);
 		assert (it != _children.end());
@@ -160,8 +160,8 @@ CompositePdfOperator::getChildren (PdfOp
 //
 //
 void 
-CompositePdfOperator::insert_after (const shared_ptr<PdfOperator> oper, 
-									shared_ptr<PdfOperator> newOper)
+CompositePdfOperator::insert_after (const boost::shared_ptr<PdfOperator> oper, 
+									boost::shared_ptr<PdfOperator> newOper)
 {
 	PdfOperators::iterator it = std::find (_children.begin(), _children.end(), oper);
 	_children.insert (++it, newOper);
@@ -189,7 +189,7 @@ CompositePdfOperator::getStringRepresent
 }
 
 void 
-CompositePdfOperator::init_operands (shared_ptr<observer::IObserver<IProperty> > observer, boost::weak_ptr<CPdf> pdf, IndiRef* rf)
+CompositePdfOperator::init_operands (boost::shared_ptr<observer::IObserver<IProperty> > observer, boost::weak_ptr<CPdf> pdf, IndiRef* rf)
 { 
 	for (PdfOperators::iterator it = _children.begin (); it != _children.end(); ++it)
 		(*it)->init_operands (observer, pdf, rf);
@@ -204,8 +204,8 @@ CompositePdfOperator::init_operands (sha
 //
 //
 //
-shared_ptr<PdfOperator> 
-getLastOperator (shared_ptr<PdfOperator> oper)
+boost::shared_ptr<PdfOperator> 
+getLastOperator (boost::shared_ptr<PdfOperator> oper)
 {
 		if (!isCompositeOp (oper) || 0 == oper->getChildrenCount())
 			return oper;
@@ -213,7 +213,7 @@ getLastOperator (shared_ptr<PdfOperator>
 	PdfOperator::PdfOperators opers;
 	oper->getChildren (opers);
 	assert (!opers.empty());
-	shared_ptr<PdfOperator> tmpop = opers.back();
+	boost::shared_ptr<PdfOperator> tmpop = opers.back();
 	while (isCompositeOp (tmpop))
 	{
 		opers.back()->getChildren (opers);
