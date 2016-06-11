--- src/kernel/cpageannots.cc.orig	2009-07-27 08:18:10 UTC
+++ src/kernel/cpageannots.cc
@@ -180,24 +180,24 @@ namespace {
 
 	typedef struct reg_annots
 	{
-		void operator() (shared_ptr<IProperty> obj, boost::shared_ptr<IPropertyObserver> obs)
+		void operator() (boost::shared_ptr<IProperty> obj, boost::shared_ptr<IPropertyObserver> obs)
 			{ REGISTER_SHAREDPTR_OBSERVER (obj, obs); }
 	}reg_annots;
 
 	typedef struct unreg_annots
 	{
-		void operator() (shared_ptr<IProperty> obj, boost::shared_ptr<IPropertyObserver> obs)
+		void operator() (boost::shared_ptr<IProperty> obj, boost::shared_ptr<IPropertyObserver> obs)
 			{ UNREGISTER_SHAREDPTR_OBSERVER (obj, obs); }
 	}unreg_annots;
 
 	// generic {un}register function
 	template<typename T>
-	void egister_annots (shared_ptr<IProperty> annots, 
+	void egister_annots (boost::shared_ptr<IProperty> annots, 
 						 T egister, 
 						 boost::shared_ptr<IPropertyObserver> _prop_wd,
 						 boost::shared_ptr<IPropertyObserver> _array_wd)
 	{
-		shared_ptr<CArray> annotsArray;
+		boost::shared_ptr<CArray> annotsArray;
 		if(isRef(annots))
 		{
 			egister(annots, _prop_wd);
@@ -237,7 +237,7 @@ namespace {
 //
 //
 void 
-CPageAnnots::reg_observers(shared_ptr<IProperty> annots)
+CPageAnnots::reg_observers(boost::shared_ptr<IProperty> annots)
 {
 		kernelPrintDbg(DBG_DBG, "");
 
@@ -251,7 +251,7 @@ CPageAnnots::reg_observers(shared_ptr<IP
 		REGISTER_SHAREDPTR_OBSERVER(_page->getDictionary(), _prop_wd);
 		if(_page->getDictionary()->containsProperty(Specification::Page::ANNOTS))
 		{
-			shared_ptr<IProperty> annotsProp=_page->getDictionary()->getProperty(Specification::Page::ANNOTS);
+			boost::shared_ptr<IProperty> annotsProp=_page->getDictionary()->getProperty(Specification::Page::ANNOTS);
 			reg_observers(annotsProp);
 		}
 	}
@@ -275,7 +275,7 @@ CPageAnnots::unreg_observers(boost::shar
 		UNREGISTER_SHAREDPTR_OBSERVER(_page->getDictionary(), _prop_wd);
 		if(_page->getDictionary()->containsProperty(Specification::Page::ANNOTS))
 		{
-			shared_ptr<IProperty> annotsProp=_page->getDictionary()->getProperty(Specification::Page::ANNOTS);
+			boost::shared_ptr<IProperty> annotsProp=_page->getDictionary()->getProperty(Specification::Page::ANNOTS);
 			unreg_observers(annotsProp);
 		}
 	}
@@ -299,12 +299,12 @@ CPageAnnots::consolidate(boost::shared_p
 	{
 		try
 		{
-			shared_ptr<CDict> annotDict=getCObjectFromRef<CDict>(oldValue);
+			boost::shared_ptr<CDict> annotDict=getCObjectFromRef<CDict>(oldValue);
 			Annotations::iterator i;
 			bool erased = false;
 			for(i=_annotations.begin(); i!=_annotations.end(); ++i)
 			{
-				shared_ptr<CAnnotation> annot=*i;
+				boost::shared_ptr<CAnnotation> annot=*i;
 				if(annot->getDictionary()==annotDict)
 				{
 					kernelPrintDbg(debug::DBG_DBG, "Annotation maintaining oldValue found and removed. Invalidating annotation");	
@@ -334,11 +334,11 @@ CPageAnnots::consolidate(boost::shared_p
 	{
 		try
 		{
-			shared_ptr<CDict> annotDict=getCObjectFromRef<CDict>(newValue);		
+			boost::shared_ptr<CDict> annotDict=getCObjectFromRef<CDict>(newValue);		
 
 			// creates CAnnotation instance from dereferenced dictionary 
 			// and adds it to _annotations
-			shared_ptr<CAnnotation> annot(new CAnnotation(annotDict));
+			boost::shared_ptr<CAnnotation> annot(new CAnnotation(annotDict));
 			_annotations.push_back(annot);
 		}catch(ElementBadTypeException & )
 		{
@@ -362,7 +362,7 @@ CPageAnnots::add(boost::shared_ptr<CAnno
 		
 	// gets Annots array from page dictionary. If no found, creates it. If bad
 	// typed, throws an exception
-	shared_ptr<CArray> annotsArray;
+	boost::shared_ptr<CArray> annotsArray;
 	try
 	{
 		annotsArray=getAnnotsArray(_page->getDictionary());
@@ -395,7 +395,7 @@ CPageAnnots::add(boost::shared_ptr<CAnno
 	IndiRef annotRef=pdf->addIndirectProperty(annot->getDictionary());
 	
 	// gets added annotation dictionary
-	shared_ptr<CDict> annotDict=IProperty::getSmartCObjectPtr<CDict>(
+	boost::shared_ptr<CDict> annotDict=IProperty::getSmartCObjectPtr<CDict>(
 			pdf->getIndirectProperty(annotRef)
 			);
 
@@ -403,7 +403,7 @@ CPageAnnots::add(boost::shared_ptr<CAnno
 	// updates P field with reference to this page
 	// This is not explictly required by specification for all annotation types,
 	// but is not an error to supply this information
-	shared_ptr<CRef> pageRef(CRefFactory::getInstance(_page->getDictionary()->getIndiRef()));
+	boost::shared_ptr<CRef> pageRef(CRefFactory::getInstance(_page->getDictionary()->getIndiRef()));
 	checkAndReplace(annotDict, "P", *pageRef);
 
 	kernelPrintDbg(debug::DBG_INFO, "Adding reference "<<annotRef<<" to annotation dictionary to Annots array");
@@ -427,7 +427,7 @@ CPageAnnots::del(boost::shared_ptr<CAnno
 	size_t pos=0;
 	for(Annotations::iterator i=_annotations.begin(); i!=_annotations.end(); ++i,++pos)
 	{
-		shared_ptr<CAnnotation> element=*i;	
+		boost::shared_ptr<CAnnotation> element=*i;	
 		if(annot!=element)
 			continue;
 		
@@ -436,7 +436,7 @@ CPageAnnots::del(boost::shared_ptr<CAnno
 		kernelPrintDbg(debug::DBG_DBG, "Annotation found. Indiref="<<annotRef);
 		try
 		{
-			shared_ptr<CArray> annotArray=getAnnotsArray(_page->getDictionary());
+			boost::shared_ptr<CArray> annotArray=getAnnotsArray(_page->getDictionary());
 			// deleting of this reference triggers annotsWatchDog observer which
 			// will synchronize _annotations with current state
 			annotArray->delProperty(pos);
@@ -476,13 +476,13 @@ using namespace observer;
 	}
 	
 	kernelPrintDbg(DBG_DBG, "context type="<<context->getType());
-	shared_ptr<IProperty> oldValue;
+	boost::shared_ptr<IProperty> oldValue;
 	switch(context->getType())
 	{
 		case BasicChangeContextType:
 			{
 				// this means that Annots element reference value has changed	
-				shared_ptr<const BasicChangeContext<IProperty> > basicContext=
+				boost::shared_ptr<const BasicChangeContext<IProperty> > basicContext=
 					dynamic_pointer_cast<const BasicChangeContext<IProperty>, const observer::IChangeContext<IProperty> >(context); 
 				oldValue=basicContext->getOriginalValue();
 				assert(isRef(newValue));
@@ -494,7 +494,7 @@ using namespace observer;
 		case ComplexChangeContextType:
 			{
 				// Annots array content has changed
-				shared_ptr<const CArray::CArrayComplexObserverContext > basicContext=
+				boost::shared_ptr<const CArray::CArrayComplexObserverContext > basicContext=
 					dynamic_pointer_cast<const CArray::CArrayComplexObserverContext, 
 					const IChangeContext<IProperty> >(context); 
 				if(!context)
@@ -540,14 +540,14 @@ CPageAnnots::PropWatchDog::notify(
 	}
 	
 	kernelPrintDbg(DBG_DBG, "context type="<<context->getType());
-	shared_ptr<IProperty> oldValue;
+	boost::shared_ptr<IProperty> oldValue;
 	switch(context->getType())
 	{
 		case BasicChangeContextType:
 			{
 				// This means that Annots property is reference and it has
 				// changed its reference value
-				shared_ptr<const observer::BasicChangeContext<IProperty> > basicContext=
+				boost::shared_ptr<const observer::BasicChangeContext<IProperty> > basicContext=
 					dynamic_pointer_cast<const observer::BasicChangeContext<IProperty>, const observer::IChangeContext<IProperty> >(context); 
 				oldValue=basicContext->getOriginalValue();
 				assert(isRef(newValue));
@@ -559,7 +559,7 @@ CPageAnnots::PropWatchDog::notify(
 				// page dictionary has changed
 				// checks identificator of changed property and if it is not
 				// Annots, immediately returns
-				shared_ptr<const CDict::CDictComplexObserverContext > basicContext=
+				boost::shared_ptr<const CDict::CDictComplexObserverContext > basicContext=
 					dynamic_pointer_cast<const CDict::CDictComplexObserverContext, 
 					const IChangeContext<IProperty> >(context); 
 				if(!basicContext)
@@ -588,7 +588,7 @@ CPageAnnots::PropWatchDog::notify(
 	// gets original annots array and unregisters all observers
 	// doesn't unregister observer from Annots property, because it is done only
 	// in case of complex context
-	shared_ptr<IProperty> oldArray;
+	boost::shared_ptr<IProperty> oldArray;
 	if(isRef(oldValue))
 	{
 		try
@@ -618,7 +618,7 @@ CPageAnnots::PropWatchDog::notify(
 	// registers obsevers to newValue annotation array - Annots property doesn't
 	// need obsever registration for same reason as oldValue doesn't need
 	// unregistration
-	shared_ptr<IProperty> newArray;
+	boost::shared_ptr<IProperty> newArray;
 	if(isRef(newValue))
 	{
 		try
