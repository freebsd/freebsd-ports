--- src/kernel/cpagecontents.cc.orig	2010-04-30 12:44:30 UTC
+++ src/kernel/cpagecontents.cc
@@ -55,8 +55,8 @@ using namespace utils;
 //
 //
 void 
-CPageContents::ContentsWatchDog::notify (shared_ptr<IProperty> newValue, 
-						  shared_ptr<const IProperty::ObserverContext> context) const throw()
+CPageContents::ContentsWatchDog::notify (boost::shared_ptr<IProperty> newValue, 
+						  boost::shared_ptr<const IProperty::ObserverContext> context) const throw()
 {
 		kernelPrintDbg (debug::DBG_DBG, "context type=" << context->getType());
 
@@ -84,7 +84,7 @@ CPageContents::ContentsWatchDog::notify 
 		case ComplexChangeContextType:
 		{
 			// Is it a dictionary Page dictionary
-			shared_ptr<const CDict::CDictComplexObserverContext> ctxtdict =
+			boost::shared_ptr<const CDict::CDictComplexObserverContext> ctxtdict =
 				dynamic_pointer_cast<const CDict::CDictComplexObserverContext, 
 									 const IChangeContext<IProperty> > (context); 
 			if (ctxtdict)
@@ -102,7 +102,7 @@ CPageContents::ContentsWatchDog::notify 
 				// 1.2 Contents entry was removed
 				if (isNull(newValue))
 				{
-					shared_ptr<IProperty> oldValue = ctxtdict->getOriginalValue();
+					boost::shared_ptr<IProperty> oldValue = ctxtdict->getOriginalValue();
 					// Unregister observer
 					_cnt->unreg_observer (oldValue);
 				
@@ -116,7 +116,7 @@ CPageContents::ContentsWatchDog::notify 
 			}
 
 			// Is it an array (Contents) -- do nothing just reparse
-			shared_ptr<const CArray::CArrayComplexObserverContext> ctxtarray =
+			boost::shared_ptr<const CArray::CArrayComplexObserverContext> ctxtarray =
 				dynamic_pointer_cast<const CArray::CArrayComplexObserverContext, 
 									 const IChangeContext<IProperty> > (context); 
 			if (ctxtarray)
@@ -162,7 +162,7 @@ namespace {
 	createStreamFromObjects (const Container& cont, boost::weak_ptr<CPdf> pdf)
 	{
 		// Create stream with one default property Length
-		shared_ptr<CStream> newstr (new CStream());
+		boost::shared_ptr<CStream> newstr (new CStream());
 		
 		// Insert our change tag
 		std::string str;
@@ -234,7 +234,7 @@ CPageContents::~CPageContents ()
 }
 
 
-shared_ptr<CContentStream> 
+boost::shared_ptr<CContentStream> 
 CPageContents::getContentStream (CContentStream* cc)
 {
 	init();
@@ -247,7 +247,7 @@ CPageContents::getContentStream (CConten
 }
 
 
-shared_ptr<CContentStream> 
+boost::shared_ptr<CContentStream> 
 CPageContents::getContentStream (size_t pos)
 {
 	init();
@@ -265,7 +265,7 @@ void 
 CPageContents::addToFront (const Container& cont)
 { 
 	// Create cstream from container of pdf operators
-	shared_ptr<CStream> stream = createStreamFromObjects (cont, _dict->getPdf());
+	boost::shared_ptr<CStream> stream = createStreamFromObjects (cont, _dict->getPdf());
 	assert (hasValidRef (stream)); assert (hasValidPdf (stream));
 	if (!hasValidPdf(stream) || !hasValidPdf(stream))
 		throw CObjInvalidObject ();
@@ -294,8 +294,8 @@ CPageContents::addToFront (const Contain
 	// Indicate change
 	change ();
 }
-template void CPageContents::addToFront<vector<shared_ptr<PdfOperator> > > (const vector<shared_ptr<PdfOperator> >& cont);
-template void CPageContents::addToFront<deque<shared_ptr<PdfOperator> > > (const deque<shared_ptr<PdfOperator> >& cont);
+template void CPageContents::addToFront<vector<boost::shared_ptr<PdfOperator> > > (const vector<boost::shared_ptr<PdfOperator> >& cont);
+template void CPageContents::addToFront<deque<boost::shared_ptr<PdfOperator> > > (const deque<boost::shared_ptr<PdfOperator> >& cont);
 
 //
 //
@@ -307,7 +307,7 @@ CPageContents::addToBack (const Containe
 	// Create cstream from container of pdf operators
 	if (!hasValidPdf(_dict))
 		throw CObjInvalidObject ();
-	shared_ptr<CStream> stream = createStreamFromObjects (cont, _dict->getPdf());
+	boost::shared_ptr<CStream> stream = createStreamFromObjects (cont, _dict->getPdf());
 	assert (hasValidRef (stream)); assert (hasValidPdf (stream));
 	if (!hasValidPdf(stream) || !hasValidPdf(stream))
 		throw CObjInvalidObject ();
@@ -332,8 +332,8 @@ CPageContents::addToBack (const Containe
 	// Indicate change
 	change ();
 }
-template void CPageContents::addToBack<vector<shared_ptr<PdfOperator> > > (const vector<shared_ptr<PdfOperator> >& cont);
-template void CPageContents::addToBack<deque<shared_ptr<PdfOperator> > > (const deque<shared_ptr<PdfOperator> >& cont);
+template void CPageContents::addToBack<vector<boost::shared_ptr<PdfOperator> > > (const vector<boost::shared_ptr<PdfOperator> >& cont);
+template void CPageContents::addToBack<deque<boost::shared_ptr<PdfOperator> > > (const deque<boost::shared_ptr<PdfOperator> >& cont);
 
 
 //
@@ -379,6 +379,12 @@ CPageContents::getText (std::string& tex
 
 	// Get the text
 	libs::Rectangle rec = (rc)? *rc : _page->display()->getPageRect();
+	// if we use rotation 90,270 then we must change the rectangle from which we want the text
+	// accordingly (TODO - verify for all rotations)
+	int rot = _page->getRotation ();
+	if (90 == rot || 270 == rot)
+		std::swap (rec.xright, rec.yright);
+
 	scoped_ptr<GString> gtxt (textDev->getText(rec.xleft, rec.yleft, rec.xright, rec.yright));
 	text = gtxt->getCString();
 }
@@ -484,11 +490,11 @@ CPageContents::addText (const std::strin
 	if (fontName.empty())
 		fontName = "PDFEDIT_F1";
     double fontSize = 15.0;
-    shared_ptr<UnknownCompositePdfOperator> q(new UnknownCompositePdfOperator("q", "Q"));
-    shared_ptr<UnknownCompositePdfOperator> BT(new UnknownCompositePdfOperator("BT", "ET"));
+    boost::shared_ptr<UnknownCompositePdfOperator> q(new UnknownCompositePdfOperator("q", "Q"));
+    boost::shared_ptr<UnknownCompositePdfOperator> BT(new UnknownCompositePdfOperator("BT", "ET"));
     PdfOperator::Operands fontOperands;
-    fontOperands.push_back(shared_ptr<IProperty>(new CName (fontName)) );
-    fontOperands.push_back(shared_ptr<IProperty>(new CReal (fontSize)));
+    fontOperands.push_back(boost::shared_ptr<IProperty>(new CName (fontName)) );
+    fontOperands.push_back(boost::shared_ptr<IProperty>(new CReal (fontSize)));
     q->push_back(BT,q);
     BT->push_back(createOperator("Tf", fontOperands), getLastOperator(BT));
     
@@ -497,13 +503,13 @@ CPageContents::addText (const std::strin
     BT->push_back(createOperator("Tm", posOperands), getLastOperator(BT));
 
     PdfOperator::Operands textOperands;
-    textOperands.push_back(shared_ptr<IProperty>(new CString (what)));
+    textOperands.push_back(boost::shared_ptr<IProperty>(new CString (what)));
     BT->push_back(createOperator("Tj", textOperands), getLastOperator(BT));
     PdfOperator::Operands emptyOperands;
     BT->push_back(createOperator("ET", emptyOperands), getLastOperator(BT));
     q->push_back(createOperator("Q", emptyOperands), getLastOperator(q));
     
-	std::vector<shared_ptr<PdfOperator> > contents;
+	std::vector<boost::shared_ptr<PdfOperator> > contents;
     contents.push_back(q);
     
 	addToBack (contents);
@@ -531,7 +537,7 @@ CPageContents::addInlineImage (const CSt
 	// EI
 	// Q
 	//
-    shared_ptr<UnknownCompositePdfOperator> q(new UnknownCompositePdfOperator("q", "Q"));
+    boost::shared_ptr<UnknownCompositePdfOperator> q(new UnknownCompositePdfOperator("q", "Q"));
 
 	// translate
 	q->push_back(createOperatorTranslation(where.x, where.y), getLastOperator(q));
@@ -540,19 +546,23 @@ CPageContents::addInlineImage (const CSt
 
 
 	CDict image_dict;
-	image_dict.addProperty ("W", CInt (image_size.x));
-	image_dict.addProperty ("H", CInt (image_size.y));
-	image_dict.addProperty ("CS", CName ("RGB"));
-	image_dict.addProperty ("BPC", CInt (8));
+	CInt x (image_size.x);
+	image_dict.addProperty ("W", x);
+	CInt y (image_size.y);
+	image_dict.addProperty ("H", y);
+	CName n ("RGB");
+	image_dict.addProperty ("CS", n);
+	CInt i (8);
+	image_dict.addProperty ("BPC", i);
 	CInlineImage img (image_dict, what);
-	shared_ptr<CInlineImage> inline_image (new CInlineImage (image_dict, what));
-	shared_ptr<InlineImageCompositePdfOperator> BI(new InlineImageCompositePdfOperator (inline_image));
+	boost::shared_ptr<CInlineImage> inline_image (new CInlineImage (image_dict, what));
+	boost::shared_ptr<InlineImageCompositePdfOperator> BI(new InlineImageCompositePdfOperator (inline_image));
     
 	q->push_back(BI,getLastOperator(q));
 	PdfOperator::Operands o;
     q->push_back(createOperator("Q", o), getLastOperator(q));
     
-	std::vector<shared_ptr<PdfOperator> > contents;
+	std::vector<boost::shared_ptr<PdfOperator> > contents;
     contents.push_back(q);
     
 	addToBack (contents);
@@ -595,7 +605,7 @@ namespace {
 	// addSomewhere
 	template<OPERWHERE WHERE>
 	void
-	cc_add (shared_ptr<CDict> _dict, CRef& ref)
+	cc_add (boost::shared_ptr<CDict> _dict, CRef& ref)
 	{
 		// contents not present
 		if (!_dict->containsProperty (Specification::Page::CONTENTS))
@@ -607,8 +617,8 @@ namespace {
 		// contents present
 		}else
 		{
-			shared_ptr<IProperty> content = _dict->getProperty (Specification::Page::CONTENTS);
-			shared_ptr<IProperty> realcontent = getReferencedObject(content);
+			boost::shared_ptr<IProperty> content = _dict->getProperty (Specification::Page::CONTENTS);
+			boost::shared_ptr<IProperty> realcontent = getReferencedObject(content);
 				assert (content);
 			// Contents can be either stream or an array of streams
 			if (isStream (realcontent))	
@@ -620,7 +630,7 @@ namespace {
 			}else if (isArray (realcontent))
 			{
 				// We can be sure that streams are indirect objects (pdf spec)
-				shared_ptr<CArray> array = IProperty::getSmartCObjectPtr<CArray> (realcontent);
+				boost::shared_ptr<CArray> array = IProperty::getSmartCObjectPtr<CArray> (realcontent);
 				OpTrait<WHERE>::Oper::add (*array, ref);
 			
 			}else // Neither stream nor array
@@ -672,7 +682,7 @@ CPageContents::toBack (CRef& ref)
  * Indicats that the page changed.
  */
 template<typename Cont>
-void CPageContents::setContents (shared_ptr<CDict> dict, const Cont& cont)
+void CPageContents::setContents (boost::shared_ptr<CDict> dict, const Cont& cont)
 {
 
 	if (dict->containsProperty (Specification::Page::CONTENTS))
@@ -682,7 +692,7 @@ void CPageContents::setContents (shared_
 	// Loop throug all content streams and add all cstreams from each
 	// content streams to Contents entry of page dictionary
 	//
-	typedef vector<shared_ptr<CStream> > Css;
+	typedef vector<boost::shared_ptr<CStream> > Css;
 	Css css;
 	getAllCStreams (cont, css);
 	
@@ -698,14 +708,14 @@ void CPageContents::setContents (shared_
 	}
 }
 // Explicit instantiation
-template void CPageContents::setContents<vector<shared_ptr<CContentStream> > >
-	(shared_ptr<CDict> dict, const vector<shared_ptr<CContentStream> >& cont);
+template void CPageContents::setContents<vector<boost::shared_ptr<CContentStream> > >
+	(boost::shared_ptr<CDict> dict, const vector<boost::shared_ptr<CContentStream> >& cont);
 
 //
 //
 //
 void 
-CPageContents::remove (shared_ptr<const CContentStream> cs)
+CPageContents::remove (boost::shared_ptr<const CContentStream> cs)
 {
 		if (!_dict->containsProperty (Specification::Page::CONTENTS))
 			throw CObjInvalidOperation ();
@@ -717,7 +727,7 @@ CPageContents::remove (shared_ptr<const 
 		// Loop throug all content streams and add all cstreams from each
 		// content streams to Contents entry of page dictionary
 		//
-		typedef vector<shared_ptr<CStream> > Css;
+		typedef vector<boost::shared_ptr<CStream> > Css;
 		Css css;
 		cs->getCStreams (css);
 		
@@ -743,8 +753,8 @@ CPageContents::remove (shared_ptr<const 
 void 
 CPageContents::remove (const IndiRef& rf)
 {
-	shared_ptr<IProperty> content = _dict->getProperty (Specification::Page::CONTENTS);
-	shared_ptr<IProperty> realcontent = getReferencedObject (content);
+	boost::shared_ptr<IProperty> content = _dict->getProperty (Specification::Page::CONTENTS);
+	boost::shared_ptr<IProperty> realcontent = getReferencedObject (content);
 		assert (content);
 	// Contents can be either stream or an array of streams
 	if (isStream (realcontent))	
@@ -756,7 +766,7 @@ CPageContents::remove (const IndiRef& rf
 	}else if (isArray (realcontent))
 	{
 		// We can be sure that streams are indirect objects (pdf spec)
-		shared_ptr<CArray> array = IProperty::getSmartCObjectPtr<CArray> (realcontent);
+		boost::shared_ptr<CArray> array = IProperty::getSmartCObjectPtr<CArray> (realcontent);
 		for (size_t i = 0; i < array->getPropertyCount(); ++i)
 		{
 			IndiRef _rf = getRefFromArray (array,i);
@@ -821,7 +831,7 @@ CPageContents::parse ()
 	//
 		if (!_dict->containsProperty (Specification::Page::CONTENTS))
 			return true;
-	shared_ptr<IProperty> contents = getReferencedObject (_dict->getProperty (Specification::Page::CONTENTS));
+	boost::shared_ptr<IProperty> contents = getReferencedObject (_dict->getProperty (Specification::Page::CONTENTS));
 		assert (contents);
 	
 	CContentStream::CStreams streams;
@@ -831,13 +841,13 @@ CPageContents::parse ()
 	//
 	if (isStream (contents))	
 	{
-		shared_ptr<CStream> stream = IProperty::getSmartCObjectPtr<CStream> (contents); 
+		boost::shared_ptr<CStream> stream = IProperty::getSmartCObjectPtr<CStream> (contents); 
 		streams.push_back (stream);
 	
 	}else if (isArray (contents))
 	{
 		// We can be sure that streams are indirect objects (pdf spec)
-		shared_ptr<CArray> array = IProperty::getSmartCObjectPtr<CArray> (contents); 
+		boost::shared_ptr<CArray> array = IProperty::getSmartCObjectPtr<CArray> (contents); 
 		for (size_t i = 0; i < array->getPropertyCount(); ++i)
 			streams.push_back (getCStreamFromArray(array,i));
 		
@@ -854,7 +864,7 @@ CPageContents::parse ()
 	// True if Contents is not [ ]
 	while (!streams.empty())
 	{
-		shared_ptr<CContentStream> cc (new CContentStream(streams,state,res));
+		boost::shared_ptr<CContentStream> cc (new CContentStream(streams,state,res));
 		// Save smart pointer of the content stream so pdfoperators can return it
 		cc->setSmartPointer (cc);
 		_ccs.push_back (cc);
@@ -911,7 +921,7 @@ CPageContents::reg_observer (boost::shar
 		// If it contains Contents register observer on it too
 		if (_dict->containsProperty(Specification::Page::CONTENTS))
 		{
-			shared_ptr<IProperty> prop = _dict->getProperty(Specification::Page::CONTENTS);
+			boost::shared_ptr<IProperty> prop = _dict->getProperty(Specification::Page::CONTENTS);
 			REGISTER_SHAREDPTR_OBSERVER(prop, _wd);
 		}
 	}
@@ -933,7 +943,7 @@ CPageContents::unreg_observer (boost::sh
 		// Unregister contents observer
 		if (_dict->containsProperty(Specification::Page::CONTENTS))
 		{
-			shared_ptr<IProperty> prop = _dict->getProperty(Specification::Page::CONTENTS);
+			boost::shared_ptr<IProperty> prop = _dict->getProperty(Specification::Page::CONTENTS);
 			UNREGISTER_SHAREDPTR_OBSERVER(prop, _wd);
 		}
 	}
@@ -963,7 +973,7 @@ CPageContents::_page_pos () const
 //
 //
 void 
-CPageContents::moveAbove (shared_ptr<const CContentStream> ct)
+CPageContents::moveAbove (boost::shared_ptr<const CContentStream> ct)
 {
 	// Get the next item
 	init();
@@ -975,7 +985,7 @@ CPageContents::moveAbove (shared_ptr<con
 			throw OutOfRange ();
 
 	// Delete next item but store it
-	shared_ptr<CContentStream> tmp = *itNext;
+	boost::shared_ptr<CContentStream> tmp = *itNext;
 	_ccs.erase (itNext, itNext + 1);
 	// Insert stored item before supplied (simply swap ct with the next item)
 	_ccs.insert (find (_ccs.begin(), _ccs.end(), ct), tmp);
@@ -993,7 +1003,7 @@ CPageContents::moveAbove (shared_ptr<con
 //
 //
 void 
-CPageContents::moveBelow (shared_ptr<const CContentStream> ct)
+CPageContents::moveBelow (boost::shared_ptr<const CContentStream> ct)
 {
 	// Get the item index
 	unsigned int pos = 0;
@@ -1007,7 +1017,7 @@ CPageContents::moveBelow (shared_ptr<con
 			throw CObjInvalidOperation ();
 	
 	// Swap
-	shared_ptr<CContentStream> tmp = _ccs[pos];
+	boost::shared_ptr<CContentStream> tmp = _ccs[pos];
 	_ccs[pos] = _ccs[pos - 1];
 	_ccs[pos - 1] = tmp;
 
