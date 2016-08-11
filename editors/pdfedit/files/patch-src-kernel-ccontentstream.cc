--- src/kernel/ccontentstream.cc.orig	2010-04-27 18:42:09 UTC
+++ src/kernel/ccontentstream.cc
@@ -68,7 +68,7 @@ namespace {
 	 * @param observer Operand observer.
 	 */
 	void
-	opsSetPdfRefCs (shared_ptr<PdfOperator> first, 
+	opsSetPdfRefCs (boost::shared_ptr<PdfOperator> first, 
 					boost::weak_ptr<CPdf> pdf, 
 					IndiRef rf, 
 					CContentStream& cs, 
@@ -204,7 +204,7 @@ namespace {
 			}else 
 			{// We have an OPERAND
 				
-				shared_ptr<IProperty> pIp (createObjFromXpdfObj (*o));
+				boost::shared_ptr<IProperty> pIp (createObjFromXpdfObj (*o));
 				operands.push_back (pIp);
 			}
 
@@ -223,14 +223,14 @@ namespace {
 	 * @param streamreader CStreams parser from which we get an xpdf object.
 	 * @param operands Operands of operator. They are shared through subcalls.
 	 */
-	shared_ptr<PdfOperator>
+	boost::shared_ptr<PdfOperator>
 	createOperatorFromStream (CStreamsXpdfReader<CContentStream::CStreams>& streamreader, 
 					PdfOperator::Operands& operands)
 	{
 		// Get operands
 		boost::shared_ptr< ::Object> o(XPdfObjectFactory::getInstance(), xpdf::object_deleter());
 		if (!createOperandsFromStream (streamreader, operands, o))
-			return shared_ptr<PdfOperator> ();
+			return boost::shared_ptr<PdfOperator> ();
 		
 		//
 		// SPECIAL CASE for inline image (stream within a text stream)
@@ -246,8 +246,8 @@ namespace {
 				throw ElementBadTypeException ("Content stream operator has incorrect operand type.");
 			}
 			
-			shared_ptr<CInlineImage> inimg (getInlineImage (streamreader));
-			return shared_ptr<PdfOperator> (new InlineImageCompositePdfOperator (inimg, chcktp->name, chcktp->endTag));
+			boost::shared_ptr<CInlineImage> inimg (getInlineImage (streamreader));
+			return boost::shared_ptr<PdfOperator> (new InlineImageCompositePdfOperator (inimg, chcktp->name, chcktp->endTag));
 		}
 
 		// factory function for all other operators
@@ -269,11 +269,11 @@ namespace {
 	 *
 	 * @return New pdf operator.
 	 */
-	shared_ptr<PdfOperator>
+	boost::shared_ptr<PdfOperator>
 	parseOp (CStreamsXpdfReader<CContentStream::CStreams>& streamreader, PdfOperator::Operands& operands)
 	{
 		// Create operator with its operands
-		shared_ptr<PdfOperator> result = createOperatorFromStream (streamreader, operands);
+		boost::shared_ptr<PdfOperator> result = createOperatorFromStream (streamreader, operands);
 	
 		if (result && isCompositeOp (result) && !isInlineImageOp (result))
 		{
@@ -283,7 +283,7 @@ namespace {
 			bool foundEndTag = false;
 			
 			// The same as in (re)parse
-			shared_ptr<PdfOperator> newop, previousLast = result;
+			boost::shared_ptr<PdfOperator> newop, previousLast = result;
 
 			//
 			// Use recursion to get all operators
@@ -348,7 +348,7 @@ namespace {
 			if (!hasValidPdf (*it) || !hasValidRef (*it))
 				throw CObjInvalidObject ();
 		}
-		weak_ptr<CPdf> pdf = streams.front()->getPdf ();
+		boost::weak_ptr<CPdf> pdf = streams.front()->getPdf ();
 		assert (pdf.lock());
 		IndiRef rf = streams.front()->getIndiRef ();
 
@@ -357,8 +357,8 @@ namespace {
 		streamreader.open ();
 	
 		PdfOperator::Operands operands;
-		shared_ptr<PdfOperator> topoperator (new UnknownCompositePdfOperator ("",""));	
-		shared_ptr<PdfOperator> newop, previousLast = topoperator;
+		boost::shared_ptr<PdfOperator> topoperator (new UnknownCompositePdfOperator ("",""));	
+		boost::shared_ptr<PdfOperator> newop, previousLast = topoperator;
 
 		//
 		// Parsing can throw, if so the stream is invalid
@@ -469,10 +469,10 @@ namespace {
 		typedef PdfOperator::BBox BBox;
 
 		// Init resources
-		void operator() (shared_ptr<GfxResources>) const {}
+		void operator() (boost::shared_ptr<GfxResources>) const {}
 
 		// Loop through operators
-		void operator() (shared_ptr<PdfOperator> op, BBox rc, const GfxState&) const
+		void operator() (boost::shared_ptr<PdfOperator> op, BBox rc, const GfxState&) const
 		{
 			// If not initialized, means an error occured (missing font etc..)
 			if (!BBox::isInitialized (rc))
@@ -736,7 +736,7 @@ CContentStream::_objectChanged ()
 
 	// Notify observers
 	boost::shared_ptr<CContentStream> current (this, EmptyDeallocator<CContentStream> ());
-	this->notifyObservers (current, shared_ptr<const ObserverContext> (new BasicObserverContext (current)));
+	this->notifyObservers (current, boost::shared_ptr<const ObserverContext> (new BasicObserverContext (current)));
 }
 
 
@@ -856,7 +856,7 @@ CContentStream::insertOperator (Operator
 	// Set correct IndiRef, CPdf and cs to inserted operator
 	assert (hasValidRef (cstreams.front()));
 	assert (hasValidPdf (cstreams.front()));
-	weak_ptr<CPdf> pdf = cstreams.front()->getPdf();
+	boost::weak_ptr<CPdf> pdf = cstreams.front()->getPdf();
 	assert (pdf.lock());
 	IndiRef rf = cstreams.front()->getIndiRef ();
 	opsSetPdfRefCs (newOper, pdf, rf, *this, operandobserver);
@@ -937,7 +937,7 @@ CContentStream::frontInsertOperator (boo
 	// Check whether we can make the change
 	cstreams.front()->canChange();
 	IndiRef rf = cstreams.front()->getIndiRef ();
-	weak_ptr<CPdf> pdf = cstreams.front()->getPdf();
+	boost::weak_ptr<CPdf> pdf = cstreams.front()->getPdf();
 	assert (pdf.lock());
 	// set accordingly	
 	opsSetPdfRefCs (newoper, pdf, rf, *this, operandobserver);
@@ -949,9 +949,9 @@ CContentStream::frontInsertOperator (boo
 	{ // Insert into
 		opsSetPdfRefCs (newoper, pdf, rf, *this, operandobserver);
 
-		shared_ptr<PdfOperator> secondoper = operators.front();
+		boost::shared_ptr<PdfOperator> secondoper = operators.front();
 		operators.push_front (newoper);
-		shared_ptr<PdfOperator> lastofnew = getLastOperator (newoper);
+		boost::shared_ptr<PdfOperator> lastofnew = getLastOperator (newoper);
 		secondoper->setPrev (lastofnew);
 		lastofnew->setNext (secondoper);
 	}
@@ -992,7 +992,7 @@ CContentStream::replaceOperator (Operato
 	// Set correct IndiRef, CPdf and cs to inserted operator
 	assert (hasValidRef (cstreams.front()));
 	assert (hasValidPdf (cstreams.front()));
-	weak_ptr<CPdf> pdf = cstreams.front()->getPdf();
+	boost::weak_ptr<CPdf> pdf = cstreams.front()->getPdf();
 	assert (pdf.lock());
 	IndiRef rf = cstreams.front()->getIndiRef ();
 	opsSetPdfRefCs (newOper, pdf, rf, *this, operandobserver);
