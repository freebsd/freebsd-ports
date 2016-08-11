--- src/kernel/cpdf.cc.orig	2010-04-27 18:42:09 UTC
+++ src/kernel/cpdf.cc
@@ -81,13 +81,13 @@ ostream & operator<<(ostream & stream, P
 	return stream;
 }
 
-shared_ptr<CDict> getPageTreeRoot(const boost::shared_ptr<CPdf> &pdf)
+boost::shared_ptr<CDict> getPageTreeRoot(const boost::shared_ptr<CPdf> &pdf)
 {
-	shared_ptr<CDict> result;
+	boost::shared_ptr<CDict> result;
 	
 	try
 	{
-		shared_ptr<IProperty> pagesProp=pdf->getDictionary()->getProperty("Pages");
+		boost::shared_ptr<IProperty> pagesProp=pdf->getDictionary()->getProperty("Pages");
 		if(!isRef(pagesProp))
 			// returns null dictionary
 			return result;
@@ -106,7 +106,7 @@ PageTreeNodeType getNodeType(const boost
 	PageTreeNodeType nodeType=UnknownNode;
 
 	// checks nodeProp - must be dictionary or reference to dictionary
-	shared_ptr<CDict> nodeDict;
+	boost::shared_ptr<CDict> nodeDict;
 	if(isDict(nodeProp))
 		nodeDict=IProperty::getSmartCObjectPtr<CDict>(nodeProp);
 	else
@@ -126,9 +126,9 @@ PageTreeNodeType getNodeType(const boost
 			return ErrorNode;
 	
 	// checks root node at first
-	shared_ptr<CPdf> pdf=nodeProp->getPdf().lock();
+	boost::shared_ptr<CPdf> pdf=nodeProp->getPdf().lock();
 	assert(pdf);
-	shared_ptr<CDict> rootDict=getPageTreeRoot(pdf);
+	boost::shared_ptr<CDict> rootDict=getPageTreeRoot(pdf);
 	if(rootDict==nodeDict)
 		// root dictionary found and it is same as internode
 		return RootNode;
@@ -136,7 +136,7 @@ PageTreeNodeType getNodeType(const boost
 	// given node is not root of page tree, chcecks Type field
 	if(nodeDict->containsProperty("Type"))
 	{
-		shared_ptr<IProperty> nodeType=nodeDict->getProperty("Type");
+		boost::shared_ptr<IProperty> nodeType=nodeDict->getProperty("Type");
 		try
 		{
 			if(isRef(nodeType))
@@ -159,7 +159,7 @@ PageTreeNodeType getNodeType(const boost
 	// Internode should contain at least Kids array field
 	if(nodeDict->containsProperty("Kids"))
 	{
-		shared_ptr<IProperty> kidsProp=nodeDict->getProperty("Kids");
+		boost::shared_ptr<IProperty> kidsProp=nodeDict->getProperty("Kids");
 		if(isArray(kidsProp))
 			return InterNode;
 		if(isRef(kidsProp))
@@ -189,8 +189,8 @@ void getKidsFromInterNode(const boost::s
 	// tries to get Kids array
 	if(interNodeDict->containsProperty("Kids"))
 	{
-		shared_ptr<IProperty> kidsProp=interNodeDict->getProperty("Kids");
-		shared_ptr<CArray> kidsArray;
+		boost::shared_ptr<IProperty> kidsProp=interNodeDict->getProperty("Kids");
+		boost::shared_ptr<CArray> kidsArray;
 		if(isRef(kidsProp))
 		{
 			try
@@ -341,17 +341,17 @@ using namespace debug;
 	if(!withSubTree)
 		return;
 
-	shared_ptr<IProperty> nodeProp=pdf->getIndirectProperty(ref);	
+	boost::shared_ptr<IProperty> nodeProp=pdf->getIndirectProperty(ref);	
 	if(getNodeType(nodeProp)>=InterNode)
 	{
 		ChildrenStorage childs;
 		assert(isDict(nodeProp));
-		shared_ptr<CDict> nodeDict=IProperty::getSmartCObjectPtr<CDict>(nodeProp);
+		boost::shared_ptr<CDict> nodeDict=IProperty::getSmartCObjectPtr<CDict>(nodeProp);
 		getKidsFromInterNode(nodeDict, childs);
 		utilsPrintDbg(DBG_DBG, "discarding all nodes in "<<ref<<" subtree");
 		for(ChildrenStorage::iterator i=childs.begin(); i!=childs.end(); ++i)
 		{
-			shared_ptr<IProperty> child=*i;
+			boost::shared_ptr<IProperty> child=*i;
 			if(!isRef(child))
 				// skip array mess
 				continue;
@@ -373,7 +373,7 @@ size_t getKidsCount(const boost::shared_
 	
 	// gets dictionary from given property. If reference, gets target object. If
 	// it is not a dictionary, returns with 0
-	shared_ptr<CDict> interNodeDict;
+	boost::shared_ptr<CDict> interNodeDict;
 	if(isRef(interNodeProp))
 	{
 		try
@@ -409,7 +409,7 @@ size_t getKidsCount(const boost::shared_
 	getKidsFromInterNode(interNodeDict, children);
 	for(ChildrenStorage::const_iterator i=children.begin(); i!=children.end(); ++i)
 	{
-		shared_ptr<IProperty> childProp=*i;
+		boost::shared_ptr<IProperty> childProp=*i;
 		if(isRef(childProp))
 			count+=getKidsCount(childProp, cache);
 	}
@@ -441,7 +441,7 @@ boost::shared_ptr<CDict> findPageDict(
 	// dictionary smart pointer holder
 	// it is initialized according pagesDict parameter - if it is reference
 	// it has to be dereferenced
-	shared_ptr<CDict> dict_ptr;
+	boost::shared_ptr<CDict> dict_ptr;
 
 	// checks if given parameter is reference and if so, dereference it
 	// using getIndirectProperty method and casts to dict_ptr
@@ -523,7 +523,7 @@ boost::shared_ptr<CDict> findPageDict(
 		size_t min_pos=startPos, index=0;
 		for(ChildrenStorage::iterator i=children.begin(); i!=children.end(); ++i, ++index)
 		{
-			shared_ptr<IProperty> child=*i;
+			boost::shared_ptr<IProperty> child=*i;
 
 			if(!isRef(child))
 			{
@@ -542,7 +542,7 @@ boost::shared_ptr<CDict> findPageDict(
 
 			// gets child dictionary (everything is checked, so no exception can
 			// be thrown here)
-			shared_ptr<CDict> child_ptr=getCObjectFromRef<CDict>(child); 
+			boost::shared_ptr<CDict> child_ptr=getCObjectFromRef<CDict>(child); 
 			
 			utilsPrintDbg(DBG_DBG, "kid["<<index<<"] node type="<<nodeType);
 
@@ -632,9 +632,9 @@ boost::shared_ptr<CDict> findPageDict(
  * superNode.
  */
 size_t searchTreeNode(
-		shared_ptr<const CPdf> pdf, 
-		shared_ptr<CDict> superNode, 
-		shared_ptr<CDict> node, 
+		boost::shared_ptr<const CPdf> pdf, 
+		boost::shared_ptr<CDict> superNode, 
+		boost::shared_ptr<CDict> node, 
 		size_t startValue, 
 		PageTreeNodeCountCache * cache)
 {
@@ -673,7 +673,7 @@ size_t searchTreeNode(
 	getKidsFromInterNode(superNode, children);
 	for(i=children.begin(); i!=children.end(); ++i, ++index)
 	{
-		shared_ptr<IProperty> child=*i;
+		boost::shared_ptr<IProperty> child=*i;
 		
 		// each element has to be reference
 		if(!isRef(child))
@@ -693,7 +693,7 @@ size_t searchTreeNode(
 
 		// dereference target dictionary - never throws, because we have checked
 		// node type
-		shared_ptr<CDict> elementDict_ptr=getCObjectFromRef<CDict>(child);
+		boost::shared_ptr<CDict> elementDict_ptr=getCObjectFromRef<CDict>(child);
 	
 		// compares elementDict_ptr (kid) with node, if they are same, returns
 		// startValue
@@ -723,7 +723,7 @@ size_t searchTreeNode(
 		IndiRef nodeRef=node->getIndiRef();
 		for(;i!=children.end(); ++i, ++index)
 		{
-			shared_ptr<IProperty> child=*i;
+			boost::shared_ptr<IProperty> child=*i;
 			if(isRef(child) && getValueFromSimple<CRef>(child)==nodeRef)
 			{
 				utilsPrintDbg(DBG_WARN, "Internode "<<superNode->getIndiRef()<<" is ambiguous. Kids["<<index<<"] duplicates reference to node.");
@@ -735,7 +735,7 @@ size_t searchTreeNode(
 	return position;
 }
 
-size_t getNodePosition(const shared_ptr<CPdf> &pdf, const shared_ptr<IProperty> &node, PageTreeNodeCountCache * cache)
+size_t getNodePosition(const boost::shared_ptr<CPdf> &pdf, const boost::shared_ptr<IProperty> &node, PageTreeNodeCountCache * cache)
 {
 	utilsPrintDbg(DBG_DBG, "");
 	// node must be from given pdf
@@ -746,7 +746,7 @@ size_t getNodePosition(const shared_ptr<
 	}
 	
 	// gets page tree root - if not found, then PageNotFoundException is thrown
-	shared_ptr<CDict> rootDict_ptr=getPageTreeRoot(pdf);
+	boost::shared_ptr<CDict> rootDict_ptr=getPageTreeRoot(pdf);
 	if(!rootDict_ptr.get())
 		throw PageNotFoundException(0);
 	
@@ -760,7 +760,7 @@ size_t getNodePosition(const shared_ptr<
 		utilsPrintDbg(DBG_ERR, "Given node is not reference nor dictionary. type="<<nodeType);
 		throw ElementBadTypeException("node");
 	}
-	shared_ptr<CDict> nodeDict_ptr;
+	boost::shared_ptr<CDict> nodeDict_ptr;
 	if(isRef(node))
 		nodeDict_ptr=getCObjectFromRef<CDict>(node);
 	else
@@ -776,7 +776,7 @@ size_t getNodePosition(const shared_ptr<
 	throw PageNotFoundException(0);
 }
 
-bool isNodeDescendant(const boost::shared_ptr<CPdf>& pdf, const IndiRef &parent, const shared_ptr<CDict> &child)
+bool isNodeDescendant(const boost::shared_ptr<CPdf>& pdf, const IndiRef &parent, const boost::shared_ptr<CDict> &child)
 {
 using namespace utils;
 
@@ -787,7 +787,7 @@ using namespace utils;
 	}
 	
 	// gets parent property
-	shared_ptr<IProperty> parentProp=child->getProperty("Parent");
+	boost::shared_ptr<IProperty> parentProp=child->getProperty("Parent");
 	if(!isRef(parentProp))
 	{
 		// parent is incorect
@@ -804,7 +804,7 @@ using namespace utils;
 	// referencies are not same, so gets parent dictionary and checks its parent
 	try
 	{
-		shared_ptr<CDict> parentDict=getCObjectFromRef<CDict>(parentProp);
+		boost::shared_ptr<CDict> parentDict=getCObjectFromRef<CDict>(parentProp);
 		return isNodeDescendant(pdf, parent, parentDict);
 	}catch(CObjectException & )
 	{
@@ -830,7 +830,7 @@ using namespace pdfobjects::utils;
 		return;
 
 	// gets dictionary from given property
-	shared_ptr<CDict> dict_ptr;
+	boost::shared_ptr<CDict> dict_ptr;
 	if(isRef(prop))
 	{
 		try
@@ -854,8 +854,8 @@ using namespace pdfobjects::utils;
 	if(!dict_ptr->containsProperty("Kids"))
 		return;
 
-	shared_ptr<IProperty> kidsProp_ptr=dict_ptr->getProperty("Kids");
-	shared_ptr<CArray> kids_ptr;
+	boost::shared_ptr<IProperty> kidsProp_ptr=dict_ptr->getProperty("Kids");
+	boost::shared_ptr<CArray> kids_ptr;
 	if(isRef(kidsProp_ptr))
 	{
 		// Kids property is reference - this is not offten but may occure and
@@ -901,7 +901,7 @@ using namespace pdfobjects::utils;
 	kids_ptr->_getAllChildObjects(container);
 	for(ChildrenStorage::iterator i=container.begin(); i!=container.end(); ++i)
 	{
-		shared_ptr<IProperty> elemProp_ptr=*i;
+		boost::shared_ptr<IProperty> elemProp_ptr=*i;
 		if(isRef(elemProp_ptr))
 		{
 			REGISTER_SHAREDPTR_OBSERVER(elemProp_ptr, pageTreeKidsObserver);
@@ -922,7 +922,7 @@ using namespace pdfobjects::utils;
 		return;
 
 	// gets dictionary from given property
-	shared_ptr<CDict> dict_ptr;
+	boost::shared_ptr<CDict> dict_ptr;
 	if(isRef(prop))
 	{
 		try
@@ -974,8 +974,8 @@ using namespace pdfobjects::utils;
 	if(!dict_ptr->containsProperty("Kids"))
 		return;
 
-	shared_ptr<IProperty> kidsProp_ptr=dict_ptr->getProperty("Kids");
-	shared_ptr<CArray> kids_ptr;
+	boost::shared_ptr<IProperty> kidsProp_ptr=dict_ptr->getProperty("Kids");
+	boost::shared_ptr<CArray> kids_ptr;
 	if(isRef(kidsProp_ptr))
 	{
 		// Kids property is reference - this is not offten but may occure and
@@ -1021,7 +1021,7 @@ using namespace pdfobjects::utils;
 	kids_ptr->_getAllChildObjects(container);
 	for(ChildrenStorage::iterator i=container.begin(); i!=container.end(); ++i)
 	{
-		shared_ptr<IProperty> elemProp_ptr=*i;
+		boost::shared_ptr<IProperty> elemProp_ptr=*i;
 		if(isRef(elemProp_ptr))
 		{
 			UNREGISTER_SHAREDPTR_OBSERVER(elemProp_ptr, pageTreeKidsObserver);
@@ -1042,7 +1042,7 @@ using namespace observer;
 using namespace utils;
 
 	assert(isActive());
-	shared_ptr<IProperty> oldValue;
+	boost::shared_ptr<IProperty> oldValue;
 	if(!context)
 	{
 		kernelPrintDbg(DBG_WARN, "No context available. Ignoring calling.");
@@ -1055,7 +1055,7 @@ using namespace utils;
 		case BasicChangeContextType:
 			{
 				// Pages reference value has changed
-				shared_ptr<const BasicChangeContext<IProperty> > basicContext=
+				boost::shared_ptr<const BasicChangeContext<IProperty> > basicContext=
 					dynamic_pointer_cast<const BasicChangeContext<IProperty>, const IChangeContext<IProperty> >(context); 
 				oldValue=basicContext->getOriginalValue();
 
@@ -1068,7 +1068,7 @@ using namespace utils;
 			{
 				// document catalog dictionary has changed. Checks valueId and
 				// proceede just if Pages property has changed
-				shared_ptr<const CDict::CDictComplexObserverContext > complexContex=
+				boost::shared_ptr<const CDict::CDictComplexObserverContext > complexContex=
 					dynamic_pointer_cast<const CDict::CDictComplexObserverContext, const IChangeContext<IProperty> >(context); 
 				if(!complexContex)
 				{
@@ -1115,7 +1115,7 @@ using namespace utils;
 	{
 		try
 		{
-			shared_ptr<IProperty> oldValueDict=getCObjectFromRef<CDict>(oldValue);
+			boost::shared_ptr<IProperty> oldValueDict=getCObjectFromRef<CDict>(oldValue);
 			kernelPrintDbg(DBG_DBG, "unregistering observers from old page tree.");
 			pdf->unregisterPageTreeObservers(oldValueDict);
 		}catch(CObjectException & e)
@@ -1136,7 +1136,7 @@ using namespace utils;
 	kernelPrintDbg(DBG_DBG, "Invalidating pageList with "<<pdf->pageList.size()<<" elements");
 	for(PageList::iterator i=pdf->pageList.begin(); i!=pdf->pageList.end(); ++i)
 	{
-		shared_ptr<CPage> page=i->second;
+		boost::shared_ptr<CPage> page=i->second;
 		page->invalidate();
 	}
 	pdf->pageList.clear();
@@ -1154,7 +1154,7 @@ using namespace utils;
 		return;
 	}
 	IndiRef newValueRef=utils::getValueFromSimple<CRef>(newValue);
-	shared_ptr<IProperty> newValueProp=pdf->getIndirectProperty(newValueRef);
+	boost::shared_ptr<IProperty> newValueProp=pdf->getIndirectProperty(newValueRef);
 	if(!isDict(newValueProp))
 	{
 		kernelPrintDbg(DBG_WARN, "Pages property doesn't refer to dictionary. type="<<newValueProp->getType());
@@ -1183,7 +1183,7 @@ using namespace observer;
 		kernelPrintDbg(DBG_WARN, "No context available. Ignoring calling.");
 		return;
 	}
-	shared_ptr<IProperty> oldValue;
+	boost::shared_ptr<IProperty> oldValue;
 	ChildrenStorage oldValues, newValues;
 	kernelPrintDbg(DBG_DBG, "context type="<<context->getType());
 	switch(context->getType())
@@ -1193,7 +1193,7 @@ using namespace observer;
 				// this means that node contains Kids array with reference type
 				// and this reference has changed its value - both oldValue and
 				// newValue has to be referencies
-				shared_ptr<const BasicChangeContext<IProperty> > basicContext=
+				boost::shared_ptr<const BasicChangeContext<IProperty> > basicContext=
 					dynamic_pointer_cast<const BasicChangeContext<IProperty>, const IChangeContext<IProperty> >(context); 
 				oldValue=basicContext->getOriginalValue();
 				assert(isRef(oldValue));
@@ -1204,7 +1204,7 @@ using namespace observer;
 			{
 				// this means that inter node dictionary has changed
 				// if changed property is not Kids, immediatelly returns
-				shared_ptr<const CDict::CDictComplexObserverContext > complexContex=
+				boost::shared_ptr<const CDict::CDictComplexObserverContext > complexContex=
 					dynamic_pointer_cast<const CDict::CDictComplexObserverContext, const IChangeContext<IProperty> >(context); 
 				if(!complexContex)
 				{
@@ -1245,7 +1245,7 @@ using namespace observer;
 	try
 	{
 		// collects all children from array
-		shared_ptr<CArray> kidsArray;
+		boost::shared_ptr<CArray> kidsArray;
 		if(isRef(oldValue))
 			kidsArray=utils::getCObjectFromRef<CArray>(oldValue);
 		else
@@ -1273,7 +1273,7 @@ using namespace observer;
 	try
 	{
 		// collects all children from array
-		shared_ptr<CArray> kidsArray;
+		boost::shared_ptr<CArray> kidsArray;
 		if(isRef(newValue))
 			kidsArray=utils::getCObjectFromRef<CArray>(newValue);
 		else
@@ -1299,10 +1299,10 @@ using namespace observer;
 	IndiRef interNodeRef=(!isNull(oldValue))?oldValue->getIndiRef():newValue->getIndiRef();
 	try
 	{
-		shared_ptr<IProperty> interNodeProp=pdf->getIndirectProperty(interNodeRef);
+		boost::shared_ptr<IProperty> interNodeProp=pdf->getIndirectProperty(interNodeRef);
 		if(isDict(interNodeProp))
 		{
-			shared_ptr<CDict> interNode=IProperty::getSmartCObjectPtr<CDict>(interNodeProp);
+			boost::shared_ptr<CDict> interNode=IProperty::getSmartCObjectPtr<CDict>(interNodeProp);
 			// if consolidatePageTree hasn't kept page count numbers, total number
 			// of pages must be invalidated
 			if(!pdf->consolidatePageTree(interNode, true))
@@ -1317,12 +1317,12 @@ using namespace observer;
 	}
 
 	// removes all pages from removed array
-	shared_ptr<IProperty> null(CNullFactory::getInstance());
+	boost::shared_ptr<IProperty> null(CNullFactory::getInstance());
 	kernelPrintDbg(DBG_DBG, "Consolidating page list by removing oldValues.");
 	size_t index=0;
 	for(ChildrenStorage::iterator i=oldValues.begin(); i!=oldValues.end(); ++i, ++index)
 	{
-		shared_ptr<IProperty> child=*i;
+		boost::shared_ptr<IProperty> child=*i;
 		// consider just referencies, other elements are just mess in array
 		// unregisters observers and consolidates pageList like this node has
 		// been removed 
@@ -1341,7 +1341,7 @@ using namespace observer;
 	kernelPrintDbg(DBG_DBG, "Consolidating page list by adding newValues.");
 	for(ChildrenStorage::iterator i=newValues.begin(); i!=newValues.end(); ++i)
 	{
-		shared_ptr<IProperty> child=*i;
+		boost::shared_ptr<IProperty> child=*i;
 		// consider just referencies, other elements are just mess in array
 		// registers observers and consolidates pageList like this node has
 		// been added 
@@ -1372,7 +1372,7 @@ using namespace utils;
 	kernelPrintDbg(DBG_DBG, "contextType="<<contextType);
 	// gets original value from given context. It has to at least
 	// BasicChangeContext
-	shared_ptr<IProperty> oldValue;
+	boost::shared_ptr<IProperty> oldValue;
 	switch(contextType)
 	{
 		// This context means that just simple value has been changed and so
@@ -1381,7 +1381,7 @@ using namespace utils;
 		case BasicChangeContextType:
 			{
 				// this means that reference property has changed its value
-				shared_ptr<const BasicChangeContext<IProperty> > basicContext=
+				boost::shared_ptr<const BasicChangeContext<IProperty> > basicContext=
 					dynamic_pointer_cast<const BasicChangeContext<IProperty>, const IChangeContext<IProperty> >(context); 
 				oldValue=basicContext->getOriginalValue();
 
@@ -1393,7 +1393,7 @@ using namespace utils;
 		case ComplexChangeContextType:
 			{
 				// this means that array content has changed
-				shared_ptr<const CArray::CArrayComplexObserverContext > complexContex=
+				boost::shared_ptr<const CArray::CArrayComplexObserverContext > complexContex=
 					dynamic_pointer_cast<const CArray::CArrayComplexObserverContext, const IChangeContext<IProperty> >(context); 
 				if(!complexContex)
 				{
@@ -1455,7 +1455,7 @@ using namespace utils;
 	{
 		try
 		{
-			shared_ptr<IProperty> oldValueDict=getCObjectFromRef<CDict>(oldValue);
+			boost::shared_ptr<IProperty> oldValueDict=getCObjectFromRef<CDict>(oldValue);
 			pdf->unregisterPageTreeObservers(oldValueDict);
 		}catch(CObjectException & e)
 		{
@@ -1482,7 +1482,7 @@ using namespace utils;
 	IndiRef parentRef=ref;
 	if(getCachedValue(ref, parentRef, pdf->pageTreeKidsParentCache))
 		kernelPrintDbg(DBG_DBG, "Uses pageTreeKidsParentCache with mapping from"<<ref<<" to "<<parentRef);
-	shared_ptr<IProperty> parentProp_ptr=pdf->getIndirectProperty(parentRef);
+	boost::shared_ptr<IProperty> parentProp_ptr=pdf->getIndirectProperty(parentRef);
 	if(parentProp_ptr->getType()!=pDict)
 	{
 		// target of the parent reference is not dictionary,
@@ -1492,7 +1492,7 @@ using namespace utils;
 	}
 
 	// starts consolidation from parent intermediate node
-	shared_ptr<CDict> parentDict_ptr=IProperty::getSmartCObjectPtr<CDict>(parentProp_ptr);
+	boost::shared_ptr<CDict> parentDict_ptr=IProperty::getSmartCObjectPtr<CDict>(parentProp_ptr);
 	try
 	{
 		// if consolidatePageTree hasn't kept page count numbers, total number
@@ -1530,7 +1530,7 @@ using namespace utils;
 	{
 		try
 		{
-			shared_ptr<IProperty> newValueDict=getCObjectFromRef<CDict>(newValue);
+			boost::shared_ptr<IProperty> newValueDict=getCObjectFromRef<CDict>(newValue);
 			pdf->registerPageTreeObservers(newValueDict);
 		}catch(CObjectException & e)
 		{
@@ -1559,11 +1559,11 @@ using namespace observer;
 	}
 	if(docCatalog->containsProperty("Pages"))
 	{
-		shared_ptr<IProperty> pagesProp=docCatalog->getProperty("Pages");
+		boost::shared_ptr<IProperty> pagesProp=docCatalog->getProperty("Pages");
 		if(isRef(pagesProp))
 		{
 			UNREGISTER_SHAREDPTR_OBSERVER(pagesProp, pageTreeRootObserver);
-			shared_ptr<IProperty> pageTreeRoot=getPageTreeRoot(_this.lock());
+			boost::shared_ptr<IProperty> pageTreeRoot=getPageTreeRoot(_this.lock());
 			if(pageTreeRoot.get())
 			{
 				try
@@ -1623,7 +1623,7 @@ void CPdf::initRevisionSpecific()
 		for(IndirectMapping::iterator i=indMap.begin(); i!=indMap.end(); ++i)
 		{
 			IndiRef ref=i->first;
-			shared_ptr<IProperty> value=i->second;
+			boost::shared_ptr<IProperty> value=i->second;
 			if(!value.unique())
 				kernelPrintDbg(debug::DBG_WARN, "Somebody still holds property with with "<<ref);
 		}
@@ -1654,7 +1654,7 @@ void CPdf::initRevisionSpecific()
 	// is thrown
 	kernelPrintDbg(debug::DBG_DBG, "Getting Root field - document catalog");
 	IndiRef rootRef(xref->getRootNum(), xref->getRootGen());
-	shared_ptr<IProperty> prop_ptr=getIndirectProperty(rootRef);
+	boost::shared_ptr<IProperty> prop_ptr=getIndirectProperty(rootRef);
 	if(prop_ptr->getType()!=pDict)
 	{
 		kernelPrintDbg(debug::DBG_ERR, "Trailer dictionary doesn't point to correct document catalog "
@@ -1670,7 +1670,7 @@ void CPdf::initRevisionSpecific()
 	REGISTER_SHAREDPTR_OBSERVER(docCatalog, pageTreeRootObserver);
 	if(docCatalog->containsProperty("Pages"))
 	{
-		shared_ptr<IProperty> pagesProp=docCatalog->getProperty("Pages");
+		boost::shared_ptr<IProperty> pagesProp=docCatalog->getProperty("Pages");
 		if(isRef(pagesProp))
 			REGISTER_SHAREDPTR_OBSERVER(pagesProp, pageTreeRootObserver);
 		else
@@ -1680,7 +1680,7 @@ void CPdf::initRevisionSpecific()
 	
 	// registers pageTreeNodeObserver and pageTreeKidsObserver to page tree root
 	// dictionary which registers these observers to whole page tree structure
-	shared_ptr<IProperty> pageTreeRoot=utils::getPageTreeRoot(_this.lock());
+	boost::shared_ptr<IProperty> pageTreeRoot=utils::getPageTreeRoot(_this.lock());
 	if(pageTreeRoot.get())
 		registerPageTreeObservers(pageTreeRoot);
 }
@@ -1870,7 +1870,7 @@ boost::shared_ptr<IProperty> CPdf::getIn
 
 	// mapping doesn't exist yet, so tries to create one
 	// fetches object according reference
-	shared_ptr< ::Object> obj(XPdfObjectFactory::getInstance(), xpdf::object_deleter());
+	boost::shared_ptr< ::Object> obj(XPdfObjectFactory::getInstance(), xpdf::object_deleter());
 	assert(xref);
 	xref->fetch(ref.num, ref.gen, obj.get());
 	
@@ -1883,13 +1883,13 @@ boost::shared_ptr<IProperty> CPdf::getIn
 	if(obj->getType()!=objNull)
 	{
 		IProperty * prop=utils::createObjFromXpdfObj(_this.lock(), *obj, ref);
-		prop_ptr=shared_ptr<IProperty>(prop);
+		prop_ptr=boost::shared_ptr<IProperty>(prop);
 		indMap.insert(IndirectMapping::value_type(ref, prop_ptr));
 		kernelPrintDbg(DBG_DBG, "Mapping created for "<<ref);
 	}else
 	{
 		kernelPrintDbg(DBG_DBG, ref<<" not available or points to objNull");
-		prop_ptr=shared_ptr<CNull>(CNullFactory::getInstance());
+		prop_ptr=boost::shared_ptr<CNull>(CNullFactory::getInstance());
 	}
 
 	return prop_ptr;
@@ -1913,7 +1913,7 @@ using namespace utils;
 	// so no type check fails). We have to set this pdf temporarily, because
 	// _makeXpdfObject function sets xref to created Object from ip->getPdf().
 	// Finally restores original pdf value
-	shared_ptr<CPdf> original=ip->getPdf().lock();
+	boost::shared_ptr<CPdf> original=ip->getPdf().lock();
 	ip->setPdf(_this);
 	::Object * obj=ip->_makeXpdfObject();
 	ip->setPdf(original);
@@ -1940,7 +1940,7 @@ IndiRef CPdf::addProperty(const boost::s
 	// ip is not from same pdf - may be in different one or stand alone object
 	// toSubstitute is deep copy of ip to prevent changes in original data.
 	// Also sets same pdf as orignal to cloned to enable dereferencing
-	shared_ptr<IProperty> toSubstitute=ip->clone();
+	boost::shared_ptr<IProperty> toSubstitute=ip->clone();
 	if(hasValidPdf(ip))
 	{
 		// locks cloned object to prevent making changes (kind of workaround)
@@ -2060,8 +2060,8 @@ using namespace utils;
 						<<refEntry->first);	
 				// ip is from read pdf and so dereferences target value 					
 				// FIXME check for valid pdf
-				shared_ptr<CPdf> pdf = ip->getPdf().lock();
-				shared_ptr<IProperty> followedIp=pdf->getIndirectProperty(ipRef);
+				boost::shared_ptr<CPdf> pdf = ip->getPdf().lock();
+				boost::shared_ptr<IProperty> followedIp=pdf->getIndirectProperty(ipRef);
 
 				// adds dereferenced value using addProperty with collected
 				// container. Current mapping is set to resolving state to 
@@ -2097,7 +2097,7 @@ using namespace utils;
 	ChildrenStorage::iterator i;
 	for(i=childrenStorage.begin(); i!=childrenStorage.end(); ++i)
 	{
-		shared_ptr<IProperty> child=*i;
+		boost::shared_ptr<IProperty> child=*i;
 		if(!isRef(*child) && !isDict(*child) && !isArray(*child) && !isStream(*child))
 		{
 			// child is none of interesting type which may hold reference
@@ -2146,7 +2146,7 @@ using namespace boost;
 	}
 	
 	// checks whether given ip is from same pdf
-	shared_ptr<CPdf> ipPdf = ip->getPdf().lock();
+	boost::shared_ptr<CPdf> ipPdf = ip->getPdf().lock();
 	if(ipPdf.get()==this)
 	{
 		// ip is from same pdf and so all possible referencies are already in 
@@ -2245,7 +2245,7 @@ void CPdf::changeIndirectProperty(const 
 		throw ReadOnlyDocumentException("Document is in read-only mode.");
 	}
 
-	shared_ptr<CPdf> _thisP = _this.lock();
+	boost::shared_ptr<CPdf> _thisP = _this.lock();
 	if(utils::isEncrypted(_thisP))
 	{
 		kernelPrintDbg(DBG_WARN, "Changing properties for encrypted documents si not implemented");
@@ -2272,7 +2272,7 @@ void CPdf::changeIndirectProperty(const 
 	// changeObject may throw if we are in read only mode or if xrefwriter is
 	// in paranoid mode and type check fails - to make it easier for such a case
 	// we are using shared_ptr which handles propObject cleanup correctly
-	shared_ptr<Object> propObject(prop->_makeXpdfObject(), xpdf::object_deleter());
+	boost::shared_ptr<Object> propObject(prop->_makeXpdfObject(), xpdf::object_deleter());
 	kernelPrintDbg(DBG_DBG, "Registering change to the XRefWriter");
 	xref->changeObject(indiRef.num, indiRef.gen, propObject.get());
 
@@ -2359,10 +2359,10 @@ using namespace std;
 	kernelPrintDbg(debug::DBG_DBG,"File stream created");
 
 	// stream is ready, creates CPdf instance
-	shared_ptr<CPdf> instance;
+	boost::shared_ptr<CPdf> instance;
 	try
 	{
-		instance = shared_ptr<CPdf>(new CPdf(stream, mode), PdfFileDeleter(file));
+		instance = boost::shared_ptr<CPdf>(new CPdf(stream, mode), PdfFileDeleter(file));
 		instance->_this = instance;
 
 		// initializes revision specific data for the newest revision
@@ -2423,14 +2423,14 @@ using namespace utils;
 	// page is not available in pageList, searching has to be done
 	// find throws an exception if any problem found, otherwise pageDict_ptr
 	// contians Page dictionary at specified position.
-	shared_ptr<CDict> rootPages_ptr=getPageTreeRoot(_this.lock());
+	boost::shared_ptr<CDict> rootPages_ptr=getPageTreeRoot(_this.lock());
 	if(!rootPages_ptr.get())
 		throw PageNotFoundException(pos);
-	shared_ptr<CDict> pageDict_ptr=findPageDict(_this.lock(), rootPages_ptr, 1, pos, &nodeCountCache);
+	boost::shared_ptr<CDict> pageDict_ptr=findPageDict(_this.lock(), rootPages_ptr, 1, pos, &nodeCountCache);
 
 	// creates CPage instance from page dictionary and stores it to the pageList
 	CPage * page=CPageFactory::getInstance(pageDict_ptr);
-	shared_ptr<CPage> page_ptr(page);
+	boost::shared_ptr<CPage> page_ptr(page);
 	pageList.insert(PageList::value_type(pos, page_ptr));
 	kernelPrintDbg(DBG_DBG, "New page added to the pageList size="<<pageList.size());
 
@@ -2452,7 +2452,7 @@ using namespace utils;
 		return pageCount;
 	}
 	
-	shared_ptr<CDict> rootDict=getPageTreeRoot(_this.lock());
+	boost::shared_ptr<CDict> rootDict=getPageTreeRoot(_this.lock());
 	if(!rootDict.get())
 		return 0;
 	pageCount=getKidsCount(rootDict, &nodeCountCache);
@@ -2531,7 +2531,7 @@ size_t CPdf::getPagePosition(const boost
 }
 
 
-void CPdf::consolidatePageList(const shared_ptr<IProperty> & oldValue, const shared_ptr<IProperty> & newValue)
+void CPdf::consolidatePageList(const boost::shared_ptr<IProperty> & oldValue, const boost::shared_ptr<IProperty> & newValue)
 {
 using namespace utils;
 
@@ -2562,12 +2562,12 @@ using namespace utils;
 			{
 				kernelPrintDbg(DBG_DBG, "oldValue was simple page dictionary");
 				difference = -1;
-				shared_ptr<CDict> oldDict_ptr=getCObjectFromRef<CDict>(oldValue);
+				boost::shared_ptr<CDict> oldDict_ptr=getCObjectFromRef<CDict>(oldValue);
 
 				for(PageList::iterator i=pageList.begin(); i!=pageList.end(); ++i)
 				{
 					// checks page's dictionary with old one
-					shared_ptr<CPage> page=i->second;
+					boost::shared_ptr<CPage> page=i->second;
 					if(page->getDictionary() == oldDict_ptr)
 					{
 						i->second->invalidate();
@@ -2598,7 +2598,7 @@ using namespace utils;
 				bool found=false;
 				for(PageList::iterator i=pageList.begin(); i!=pageList.end();)
 				{
-					shared_ptr<CPage> page=i->second;
+					boost::shared_ptr<CPage> page=i->second;
 					// checks page's dictionary whether it is in oldDict_ptr sub
 					// tree and if so removes it from pageList
 					if(isNodeDescendant(_this.lock(), ref, page->getDictionary()))
@@ -2698,7 +2698,7 @@ using namespace utils;
 	for(i=pageList.begin(); i!=pageList.end();)
 	{
 		size_t pos=i->first;
-		shared_ptr<CPage> page=i->second;
+		boost::shared_ptr<CPage> page=i->second;
 
 		if(pos>=minPos)
 		{
@@ -2782,8 +2782,8 @@ using namespace utils;
 	bool countChanged=false;
 	if(interNode->containsProperty("Count"))
 	{
-		shared_ptr<IProperty> countProp=interNode->getProperty("Count");
-		shared_ptr<CInt> countInt;
+		boost::shared_ptr<IProperty> countProp=interNode->getProperty("Count");
+		boost::shared_ptr<CInt> countInt;
 		if(isRef(countProp))
 		{
 			try
@@ -2803,7 +2803,7 @@ using namespace utils;
 			interNode->delProperty("Count");
 
 			// adds new Count property with correct value
-			countInt=shared_ptr<CInt>(CIntFactory::getInstance((int)count));
+			countInt=boost::shared_ptr<CInt>(CIntFactory::getInstance((int)count));
 			kernelPrintDbg(DBG_DBG, "replacing old Count property with new property value="<<count);
 			interNode->addProperty("Count", *countInt);
 			countChanged=true;
@@ -2842,7 +2842,7 @@ using namespace utils;
 	size_t index=0;
 	for(i=kids.begin(); i!=kids.end(); ++i, ++index)
 	{
-		shared_ptr<IProperty> child=*i;
+		boost::shared_ptr<IProperty> child=*i;
 		if(!isRef(child))
 		{
 			// element is not reference, so we print warning and skip it
@@ -2861,16 +2861,16 @@ using namespace utils;
 		
 		// gets target dictionary to check and consolidate - this doesn't throw
 		// because it is leaf or intermediate node
-		shared_ptr<CDict> childDict=getCObjectFromRef<CDict>(child);
+		boost::shared_ptr<CDict> childDict=getCObjectFromRef<CDict>(child);
 		
 		// each leaf and inter node has to have Parent property with refernce to
 		// this node (which is indirect object and so we can use its
 		// NOTE that change in Parent property doesn't require also interNode
 		// parent consolidation
-		shared_ptr<CRef> parentRef;
+		boost::shared_ptr<CRef> parentRef;
 		if(childDict->containsProperty("Parent"))
 		{
-			shared_ptr<IProperty> parentProp=childDict->getProperty("Parent");
+			boost::shared_ptr<IProperty> parentProp=childDict->getProperty("Parent");
 			if(isRef(parentProp))
 				parentRef=IProperty::getSmartCObjectPtr<CRef>(parentProp);
 
@@ -2881,7 +2881,7 @@ using namespace utils;
 				childDict->delProperty("Parent");
 
 				// adds new Parent property with correct value
-				parentRef=shared_ptr<CRef>(CRefFactory::getInstance(interNodeRef));
+				parentRef=boost::shared_ptr<CRef>(CRefFactory::getInstance(interNodeRef));
 				kernelPrintDbg(DBG_DBG, "replacing old Parent property with new");
 				childDict->addProperty("Parent", *parentRef);
 			}else
@@ -2920,12 +2920,12 @@ using namespace utils;
 		// just prints warning messages and stops recursion
 		if(interNode->containsProperty("Parent"))
 		{
-			shared_ptr<IProperty> parentProp=interNode->getProperty("Parent");
+			boost::shared_ptr<IProperty> parentProp=interNode->getProperty("Parent");
 			if(isRef(parentProp))
 			{
 				try
 				{
-					shared_ptr<CDict> parentDict=getCObjectFromRef<CDict>(parentProp);
+					boost::shared_ptr<CDict> parentDict=getCObjectFromRef<CDict>(parentProp);
 					return consolidatePageTree(parentDict, true);
 				}catch(CObjectException & e)
 				{
@@ -2977,8 +2977,8 @@ using namespace utils;
 	// gets intermediate node where to insert new page
 	// in degenerated case, when there are no pages in the tree, we have to
 	// handle it special way
-	shared_ptr<CDict> interNode_ptr;
-	shared_ptr<CRef> currRef;
+	boost::shared_ptr<CDict> interNode_ptr;
+	boost::shared_ptr<CRef> currRef;
 	// by default it is root of page tree
 	interNode_ptr=getPageTreeRoot(_this.lock());
 	if(!interNode_ptr.get())
@@ -2993,23 +2993,23 @@ using namespace utils;
 		// searches for page at storePosition and gets its reference
 		// page dictionary has to be an indirect object, so getIndiRef returns
 		// dictionary reference
-		shared_ptr<CDict> currentPage_ptr=findPageDict(_this.lock(), interNode_ptr, 1, storePostion, &nodeCountCache);
-		currRef=shared_ptr<CRef>(CRefFactory::getInstance(currentPage_ptr->getIndiRef()));
+		boost::shared_ptr<CDict> currentPage_ptr=findPageDict(_this.lock(), interNode_ptr, 1, storePostion, &nodeCountCache);
+		currRef=boost::shared_ptr<CRef>(CRefFactory::getInstance(currentPage_ptr->getIndiRef()));
 		
 		// gets parent of found dictionary which maintains 
-		shared_ptr<IProperty> parentRef_ptr=currentPage_ptr->getProperty("Parent");
+		boost::shared_ptr<IProperty> parentRef_ptr=currentPage_ptr->getProperty("Parent");
 		interNode_ptr=getCObjectFromRef<CDict>(parentRef_ptr);
 	}
 
 	// gets Kids array where to insert new page dictionary
-	shared_ptr<IProperty> kidsProp_ptr=interNode_ptr->getProperty("Kids");
+	boost::shared_ptr<IProperty> kidsProp_ptr=interNode_ptr->getProperty("Kids");
 	if(kidsProp_ptr->getType()!=pArray)
 	{
 		kernelPrintDbg(DBG_ERR, "Pages Kids field is not an array type="<<kidsProp_ptr->getType());
 		// Kids is not array - malformed intermediate node
 		throw MalformedFormatExeption("Intermediate node Kids field is not an array.");
 	}
-	shared_ptr<CArray> kids_ptr=IProperty::getSmartCObjectPtr<CArray>(kidsProp_ptr);
+	boost::shared_ptr<CArray> kids_ptr=IProperty::getSmartCObjectPtr<CArray>(kidsProp_ptr);
 	
 	// gets index in Kids array where to store.
 	// by default insert at 1st position (index is 0)
@@ -3032,8 +3032,8 @@ using namespace utils;
 
 	// Now it is safe to add indirect object, because there is nothing that can
 	// fail
-	shared_ptr<CDict> pageDict=page->getDictionary();
-	shared_ptr<CPdf> pageDictPdf = pageDict->getPdf().lock();
+	boost::shared_ptr<CDict> pageDict=page->getDictionary();
+	boost::shared_ptr<CPdf> pageDictPdf = pageDict->getPdf().lock();
 	if(pageDictPdf && pageDictPdf !=_this.lock())
 	{
 		// page comes from different valid pdf - we have to create clone and
@@ -3085,8 +3085,8 @@ using namespace utils;
 	// page dictionary is stored in the tree, consolidation is also done at this
 	// moment
 	// CPage can be created and inserted to the pageList
-	shared_ptr<CDict> newPageDict_ptr=IProperty::getSmartCObjectPtr<CDict>(getIndirectProperty(pageRef));
-	shared_ptr<CPage> newPage_ptr(CPageFactory::getInstance(newPageDict_ptr));
+	boost::shared_ptr<CDict> newPageDict_ptr=IProperty::getSmartCObjectPtr<CDict>(getIndirectProperty(pageRef));
+	boost::shared_ptr<CPage> newPage_ptr(CPageFactory::getInstance(newPageDict_ptr));
 	pageList.insert(PageList::value_type(storePostion+append, newPage_ptr));
 	kernelPrintDbg(DBG_DBG, "New page added to the pageList size="<<pageList.size());
 	return newPage_ptr;
@@ -3113,21 +3113,21 @@ using namespace utils;
 	// Searches for page dictionary at given pos and gets its reference.
 	// getPageTreeRoot doesn't fail, because we are in page range and so it has
 	// to exist
-	shared_ptr<CDict> rootDict=getPageTreeRoot(_this.lock());
-	shared_ptr<CDict> currentPage_ptr=findPageDict(_this.lock(), rootDict, 1, pos, &nodeCountCache);
-	shared_ptr<CRef> currRef(CRefFactory::getInstance(currentPage_ptr->getIndiRef()));
+	boost::shared_ptr<CDict> rootDict=getPageTreeRoot(_this.lock());
+	boost::shared_ptr<CDict> currentPage_ptr=findPageDict(_this.lock(), rootDict, 1, pos, &nodeCountCache);
+	boost::shared_ptr<CRef> currRef(CRefFactory::getInstance(currentPage_ptr->getIndiRef()));
 	
 	// Gets parent field from found page dictionary and gets its Kids array
-	shared_ptr<IProperty> parentRef_ptr=currentPage_ptr->getProperty("Parent");
-	shared_ptr<CDict> interNode_ptr=getCObjectFromRef<CDict>(parentRef_ptr);
-	shared_ptr<IProperty> kidsProp_ptr=interNode_ptr->getProperty("Kids");
+	boost::shared_ptr<IProperty> parentRef_ptr=currentPage_ptr->getProperty("Parent");
+	boost::shared_ptr<CDict> interNode_ptr=getCObjectFromRef<CDict>(parentRef_ptr);
+	boost::shared_ptr<IProperty> kidsProp_ptr=interNode_ptr->getProperty("Kids");
 	if(kidsProp_ptr->getType()!=pArray)
 	{
 		kernelPrintDbg(DBG_ERR, "Pages Kids field is not an array type="<<kidsProp_ptr->getType());
 		// Kids is not array - malformed intermediate node
 		throw MalformedFormatExeption("Intermediate node Kids field is not an array.");
 	}
-	shared_ptr<CArray> kids_ptr=IProperty::getSmartCObjectPtr<CArray>(kidsProp_ptr);
+	boost::shared_ptr<CArray> kids_ptr=IProperty::getSmartCObjectPtr<CArray>(kidsProp_ptr);
 
 	// gets index of searched node in Kids array and removes element from found
 	// position - if position can't be determined unambiguously (getPropertyId
