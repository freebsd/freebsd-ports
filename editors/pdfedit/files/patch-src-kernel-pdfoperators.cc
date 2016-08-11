--- src/kernel/pdfoperators.cc.orig	2010-04-27 18:42:09 UTC
+++ src/kernel/pdfoperators.cc
@@ -129,7 +129,7 @@ SimpleGenericOperator::getStringRepresen
 //
 //
 //
-shared_ptr<PdfOperator> 
+boost::shared_ptr<PdfOperator> 
 SimpleGenericOperator::clone ()
 {
 	// Clone operands
@@ -144,7 +144,7 @@ SimpleGenericOperator::clone ()
 
 
 void 
-SimpleGenericOperator::init_operands (shared_ptr<observer::IObserver<IProperty> > observer, 
+SimpleGenericOperator::init_operands (boost::shared_ptr<observer::IObserver<IProperty> > observer, 
 									  boost::weak_ptr<CPdf> pdf, 
 									  IndiRef* rf)
 { 
@@ -204,20 +204,20 @@ using namespace utils;
 	}
 	else if (name == "TJ")
 	{
-		shared_ptr<IProperty> op = ops[0];
+		boost::shared_ptr<IProperty> op = ops[0];
 		if (!isArray(op) || ops.size() != 1)
 		{
 			utilsPrintDbg(debug::DBG_WARN, "Bad operands for TJ operator: ops[type="
 					<< op->getType() <<" size="<<ops.size()<<"]");
 			return;
 		}
-		shared_ptr<CArray> opArray = IProperty::getSmartCObjectPtr<CArray>(op);
-		std::vector<shared_ptr<IProperty> > props;
+		boost::shared_ptr<CArray> opArray = IProperty::getSmartCObjectPtr<CArray>(op);
+		std::vector<boost::shared_ptr<IProperty> > props;
 		opArray->_getAllChildObjects(props);
-		std::vector<shared_ptr<IProperty> >::iterator i;
+		std::vector<boost::shared_ptr<IProperty> >::iterator i;
 		for(i=props.begin(); i!=props.end(); ++i)
 		{
-			shared_ptr<IProperty> p = *i;
+			boost::shared_ptr<IProperty> p = *i;
 
 			// TODO consider spacing coming from values
 			if(!(isString(p)))
@@ -264,7 +264,7 @@ TextSimpleOperator::setRawText (std::str
 	}
 	else if (name == "TJ")
 	{
-		shared_ptr<IProperty> op = ops[0];
+		boost::shared_ptr<IProperty> op = ops[0];
 			if (!isArray(op) || ops.size() != 1)
 			{
 				utilsPrintDbg(debug::DBG_WARN, "Bad operands for TJ operator: ops[type="<< op->getType() <<" size="<<ops.size()<<"]");
@@ -311,7 +311,7 @@ GfxFont* TextSimpleOperator::getCurrentF
 {
 	assert(fontData);
 	const char* tag = fontData->getFontTag();
-	shared_ptr<GfxResources> res = getContentStream()->getResources(); 
+	boost::shared_ptr<GfxResources> res = getContentStream()->getResources(); 
 	GfxFont* font = res->lookupFont(tag);
 	if(!font)
 		utilsPrintDbg(debug::DBG_ERR, "Unable to get font(name="
@@ -407,10 +407,10 @@ UnknownCompositePdfOperator::getStringRe
 //
 //
 //
-shared_ptr<PdfOperator> 
+boost::shared_ptr<PdfOperator> 
 UnknownCompositePdfOperator::clone ()
 {
-	shared_ptr<UnknownCompositePdfOperator> clone (new UnknownCompositePdfOperator(_opBegin,_opEnd));
+	boost::shared_ptr<UnknownCompositePdfOperator> clone (new UnknownCompositePdfOperator(_opBegin,_opEnd));
 
 	for (PdfOperators::iterator it = _children.begin(); it != _children.end(); ++it)
 		clone->push_back ((*it)->clone(),getLastOperator(clone));
@@ -482,13 +482,13 @@ InlineImageCompositePdfOperator::getPara
 //
 //
 //
-shared_ptr<PdfOperator> 
+boost::shared_ptr<PdfOperator> 
 InlineImageCompositePdfOperator::clone ()
 {
 	// Clone operands
-	shared_ptr<CInlineImage> imgclone = IProperty::getSmartCObjectPtr<CInlineImage> (_inlineimage->clone());
+	boost::shared_ptr<CInlineImage> imgclone = IProperty::getSmartCObjectPtr<CInlineImage> (_inlineimage->clone());
 	// Create clone
-	return shared_ptr<PdfOperator> (new InlineImageCompositePdfOperator (imgclone, _opBegin, _opEnd));
+	return boost::shared_ptr<PdfOperator> (new InlineImageCompositePdfOperator (imgclone, _opBegin, _opEnd));
 }
 
 
@@ -505,7 +505,7 @@ boost::shared_ptr<PdfOperator> createOpe
 	const StateUpdater::CheckTypes* chcktp = StateUpdater::findOp (name.c_str());
 	// Operator not found, create unknown operator
 	if (NULL == chcktp)
-		return shared_ptr<PdfOperator> (new SimpleGenericOperator (name ,operands));
+		return boost::shared_ptr<PdfOperator> (new SimpleGenericOperator (name ,operands));
 	
 	assert (chcktp);
 	utilsPrintDbg (DBG_DBG, "Operator found. " << chcktp->name);
@@ -524,13 +524,13 @@ boost::shared_ptr<PdfOperator> createOpe
 	// If endTag is "" it is a simple operator, composite otherwise
 	// 
 	if (isTextOp(*chcktp))
-		return shared_ptr<PdfOperator> (new TextSimpleOperator(chcktp->name, argNum, operands));
+		return boost::shared_ptr<PdfOperator> (new TextSimpleOperator(chcktp->name, argNum, operands));
 
 	if (isSimpleOp(*chcktp))
-		return shared_ptr<PdfOperator> (new SimpleGenericOperator (chcktp->name, argNum, operands));
+		return boost::shared_ptr<PdfOperator> (new SimpleGenericOperator (chcktp->name, argNum, operands));
 		
 	// Composite operator
-	return shared_ptr<PdfOperator> (new UnknownCompositePdfOperator (chcktp->name, chcktp->endTag));
+	return boost::shared_ptr<PdfOperator> (new UnknownCompositePdfOperator (chcktp->name, chcktp->endTag));
 
 }
 
